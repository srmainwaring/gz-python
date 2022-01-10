# Python Ignition

This project provides Python bindings for [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) and [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport).


## Building with Bazel

The bindings currently expect Ignition to be built with Bazel using the build rules
from [`ign-bazel`](https://github.com/ignitionrobotics/ign-bazel). The following instructions have been adapted from `ign-bazel` for macOS Big Sur 11.6.1

### Installing Bazel

On macOS Bazel can be installed with `brew`:

```bash
brew install bazel
```

The [Google protocol buffers compiler](https://github.com/protocolbuffers/protobuf) is also required and can be installed with:


```bash
brew install protobuf
```

Confirm the installed version is `3.19`.


### Setting up the workspace

Make a directory to contain all this package and all the Ignition packages and dependencies:

```bash
mkdir ~/ignition/
cd ~/ignition/
```

Clone each of the packages using the `.repos` file and [vcstool](https://github.com/dirk-thomas/vcstool). The forked version of `ign-bazel` contains modified build rules and repo references
for macOS.

```bash
wget https://raw.githubusercontent.com/srmainwaring/ign-bazel/bazel-macos/example/bazel.repos
vcs import . < bazel.repos
```

Next, symlink the following files into the workspace directory for `bazel`:

```bash
cd ~/ignition
ln -sf ./ign_bazel/example/WORKSPACE.example ./WORKSPACE
ln -sf ./ign_bazel/example/BUILD.example ./BUILD.bazel
ln -sf ./ign_bazel/example/bazelrc.example ./.bazelrc
ln -sf ./ign_bazel/example/ign-msgs9.BUILD.example ./ign-msgs9.BUILD
```

Finally, [`pybind11_protobuf`](https://github.com/pybind/pybind11_protobuf) requires
a patch to the protobuf archive which must be available in the subdirectory
`~/ignition/external`. It must be copied rather than symlinked:

```bash
cd ~/ignition
mkdir external
cp ./python_ignition/external/com_google_protobuf_build.patch external
```

### Build with Bazel

Currently our use of `pybind11_protobuf` requires the Python implementation of the Python protobuf generator. This is configured with the environment variable:  

```bash
export PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python
```

Then build the examples with:

```bash
bazel build //python_ignition:all
bazel build //python_ignition/python:all
```

Note: on macOS not all Ignition projects will build with Bazel, so the command:

```bash
bazel build //... 
```

will result in a number of errors.

## Building with CMake

### Install Ignition

Follow the [Ignition Garden](https://ignitionrobotics.org/docs/garden) instructions for a source installation. In the following we assume the Ignition source is locked in the
workspace directory `~/workspace/src`

### Install python-ignition

Clone this repo into the workspace source directory and update external submodules:

```bash
cd ~/workspace/src
git clone https://github.com/srmainwaring/python-ignition.git -b bazel-macos/python-ignition
cd python-ignition
git submodule update --init --recursive
```

### Build with CMake

```bash
mkdir -p ~/workspace/src/python-ignition/build
cd ~/workspace/src/python-ignition/build
cmake ..
make
```

## Usage

The Bazel build file `ign-msgs9.BUILD` defines targets for a selection of messages.
For example the targets for `proto/ignition/msgs/time.proto` are:

```bash
# proto_library
@ign-msgs9//:time_proto

# cpp_proto_library
@ign-msgs9//:time_cc_proto

# python_proto_library
@ign-msgs9//:time_py_pb2
```

### `C++`

To use the bindings in C++:

```c++
// main.cc
#include "ignition/msgs/time.pb.h"
#include <iostream>

int main(int argc, const char* argv[])
{
  ignition::msgs::Time msg;
  msg.set_sec(11);
  msg.set_nsec(25);
  std::cout << msg.DebugString();
  
  return 0;
}
```

```bash
# BUILD.bazel
cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [
      "@ign-msgs9//:time_cc_proto",
  ],
)
```

### Python

To use the bindings in Python:

```python
# example.py
from ignition.msgs.time_pb2 import Time

msg = Time()
msg.sec = 15
msg.nsec = 21
print(msg)
```

```bash
# BUILD.bazel

py_binary(
  name = "example",
  srcs = ["example.py"],
  data = [
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:time_py_pb2",
  ],
)
```

## Examples

A number of examples in C++ and Python are provided.


---

`src/msg_example.cc` is a copy of the [`ign-msgs` tutorial example](https://ignitionrobotics.org/api/msgs/8.1/cppgetstarted.html):

```bash
./bazel-bin/python_ignition/msg_example
```

---

`src/publisher.cc` and `src/subscriber.cc` are copies of the [`ign-transport` messages tutorial example](https://ignitionrobotics.org/api/transport/11.0/messages.html).

From terminal 1:

```bash
./bazel-bin/python_ignition/publisher
```

From terminal 2:

```bash
./bazel-bin/python_ignition/subscriber
```

---

`src/rover_publisher.cc` and `src/rover_subscriber.cc` comprise another publish / subscribe
example that publishes the pose and twist of a rover moving in a circle with constant
angular velocity.

From terminal 1:

```bash
./bazel-bin/python_ignition/rover_publisher
```

From terminal 2:

```bash
./bazel-bin/python_ignition/rover_subscriber
```

---

`python/msgs_example.py` is a Python example that uses the generated Python protobuf libraries for `ign-msgs`:

```bash
./bazel-bin/python_ignition/python/msgs_example
```

---

`python/publisher.py` is a Python version of the C++ `src/publisher.cc` described above.
You can listen to the messages using the C++ subscriber as before.

From terminal 1:

```bash
./bazel-bin/python_ignition/python/publisher
```

From terminal 2:

```bash
./bazel-bin/python_ignition/subscriber
```

---

`python/rover_publisher.py` is a Python version of the C++ `src/rover_publisher.cc` example.

From terminal 1:

```bash
./bazel-bin/python_ignition/python/rover_publisher
```

From terminal 2:

```bash
./bazel-bin/python_ignition/rover_subscriber
```

## Notes

### Protobuf compiler version

The project depends on `protoc` version `3.19.1`. You must ensure that the version of `protoc` installed by `brew` matches (otherwise the examples will segfault).

```bash
$ protoc --version
libprotoc 3.19.1
```

### Protobuf generated Python libraries

There are some issues when using the C++ implementation of the generated
Python protobuf library. The `brew` installation of `protobuf` will default to
use the C++ implementation. To enable the Python implementation set the environment variable
before building the project:

```bash
export PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python
```


### Repos used to build Ignition on macOS with Bazel

The table summarises the dependencies (repo and branch) on the Ignition libraries.

| library | repo | branch | build | test |
| --- | --- | --- | --- | --- |
| | | | | |
|python_ignition|https://github.com/srmainwaring/python-ignition|main|pass|-|
| | | | | |
|ign-bazel|https://github.com/srmainwaring/ign-bazel|bazel-macos|pass|pass|
|ign-math|https://github.com/srmainwaring/ign-math|bazel-macos/ign-math6|pass|pass|
|ign-utils|https://github.com/srmainwaring/ign-utils|bazel-macos/ign-utils1|pass|pass|
|ign-common|https://github.com/srmainwaring/ign-common|bazel-macos/ign-common4|pass|pass|
|ign-msgs|https://github.com/srmainwaring/ign-msgs|bazel-macos/ign-msgs9|pass|pass|
|sdformat|https://github.com/ignitionrobotics/sdformat| bazel-sdf10|pass|pass|
|ign-plugin|https://github.com/srmainwaring/ign-plugin|bazel-macos/ign-plugin1|pass|pass|
|ign-transport|https://github.com/srmainwaring/ign-transport|bazel-macos/ign-transport12|pass|1 fail|
|ign-physics|https://github.com/srmainwaring/ign-physics|bazel-macos/ign-physics5|pass|pass|
|ign-tools|https://github.com/srmainwaring/ign-tools|bazel-macos/ign-tools1|partial|-|
|ign-rendering|https://github.com/ignitionrobotics/ign-rendering|bazel-rendering4|fail|fail|
|ign-gui|https://github.com/ignitionrobotics/ign-gui|bazel-gui4|fail|fail|
|ign-sensors|https://github.com/ignitionrobotics/ign-sensors|bazel-sensors4|fail|fail|
|ign-gazebo|https://github.com/ignitionrobotics/ign-gazebo|bazel-gazebo4|fail|fail|
| | | | | |