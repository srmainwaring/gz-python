# Python Ignition

This project aims to provide Python bindings for [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) and [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport). It is a work in progress...

C++ and Python libraries for [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) are generated using [Protobuf and gRPC rules for Bazel](https://rules-proto-grpc.com/en/latest/index.html).

The objective is to generate Python bindings for [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport) using [`pybind11`](https://github.com/pybind/pybind11). Interoperability between native Python protobuf
libraries and the C++ protobuf library used in the [`pybind11`](https://github.com/pybind/pybind11) extension module is provided by [`pybind11_protobuf`](https://github.com/pybind/pybind11_protobuf).

## Status

- Working bindings for a selection of [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) are available using the protocol buffers native Python implementation. The build rules for the C++ implementation are also available however there is an open issue in [`pybind11_protobuf`](https://github.com/pybind/pybind11_protobuf) that prevents full interoperability in this case (see Notes below).
- Bindings for [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport) are in development. At present only publishing messages is supported. The interface is very similar to the one available in C++.

## Install - macOS

### Prerequisites

Install [Bazel](https://bazel.build/) and the [Google protocol buffers compiler](https://github.com/protocolbuffers/protobuf) using brew:

```bash
$ brew install bazel protobuf
```

Check the installed versions (`protobuf` must be version `3.19`):

```bash
$ protoc --version
libprotoc 3.19.1

$ bazel --version
bazel 4.2.2-homebrew
```

### Set up [`ign-bazel`](https://github.com/ignitionrobotics/ign-bazel)

This project is developed on macOS and uses custom versions of some of the libraries 
referenced in https://github.com/ignitionrobotics/ign-bazel/blob/master/example/bazel.repos
which are listed in the table below.

Follow the instructions to set up
[ign-bazel](https://github.com/ignitionrobotics/ign-bazel). On macOS you will need
the repos and branches listed in the table. On other systems you will need the additional
external build file [`ign-msgs9.BUILD`](https://github.com/srmainwaring/ign-bazel/blob/bazel-macos/example/ign-msgs9.BUILD.example).

This project should be cloned into the workspace directory at the same level as the other ignition libraries. Symlink the `bazelrc`, `BUILD` and `WORKSPACE` files into the
workspace root, including the additional external `BUILD` file for `ign-msgs`:

```bash
cd ~/ignition

git clone https://github.com/srmainwaring/python-ignition.git -b bazel-macos/python-ignition python_ignition

ln -sf ./ign_bazel/example/WORKSPACE.example ./WORKSPACE
ln -sf ./ign_bazel/example/BUILD.example ./BUILD.bazel
ln -sf ./ign_bazel/example/bazelrc.example ./.bazelrc
ln -sf ./ign_bazel/example/ign-msgs9.BUILD.example ./ign-msgs9.BUILD
```

Ensure that the Python impementation of the Python protobuf generator is used:  

```bash
export PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python
```

Build the examples with

```bash
$ bazel build //python_ignition:all
$ bazel build //python_ignition/python:all
```

| library | repo | branch | build | test |
| --- | --- | --- | --- | --- |
| | | | | |
|python_ignition|https://github.com/srmainwaring/python-ignition|bazel-macos/python-ignition|pass|-|
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

To use the `ign` command line tool to view topics:

```bash
$ IGN_CONFIG_PATH=bazel-bin/ign_transport ign topic -l
```

### Example 1:

`src/msg_example.cc` is a version of the [`ign-msgs` tutorial example](https://ignitionrobotics.org/api/msgs/8.1/cppgetstarted.html). Run:

```bash
$ ./bazel-bin/python_ignition/msg_example
```

### Example 2:

`src/publisher.cc` and `src/subscriber.cc` is a version of the [`ign-transport` messages tutorial example](https://ignitionrobotics.org/api/transport/11.0/messages.html)

From terminal 1:

```bash
$ ./bazel-bin/python_ignition/publisher
```

From terminal 2:

```bash
$ ./bazel-bin/python_ignition/subscriber
```

### Example 3:

`src/rover_publisher.cc` and `src/rover_subscriber.cc` comprise another publish / subscribe
example that publishes the pose and twist of a rover moving in a circle with constant
angular velocity.

From terminal 1:

```bash
$ ./bazel-bin/python_ignition/rover_publisher
```

From terminal 2:

```bash
$ ./bazel-bin/python_ignition/rover_subscriber
```

### Example 4:

`python/msgs_example.py` is a Python example that uses the generated Python protobuf libraries for `ign-msgs`:

```bash
$ ./bazel-bin/python_ignition/python/msgs_example
```

### Example 5:

`python/publisher.py` is a Python version of the C++ `src/publisher.cc` described above.
You can listen to the messages using the C++ subscriber as before.

From terminal 1:

```bash
$ ./bazel-bin/python_ignition/python/publisher
```

From terminal 2:

```bash
$ ./bazel-bin/python_ignition/subscriber
```

### Example 6:

`python/rover_publisher.py` is a Python version of the C++ `src/rover_publisher.cc` example.

From terminal 1:

```bash
$ ./bazel-bin/python_ignition/python/rover_publisher
```

From terminal 2:

```bash
$ ./bazel-bin/python_ignition/rover_subscriber
```

## Notes and Issues

### `protoc` version

This version uses protoc version 3.19.1. You must ensure that the version of `protoc` installed by brew matches (otherwise the examples will segfault).

```bash
$ protoc --version
libprotoc 3.19.1
```

### Protobuf generated Python libraries

There are some issues when using the C++ implementation of the generated
Python protobuf library. The brew installation of `protobuf` will default to
use the C++ implementation, to enable the Python implementation set the environment variable

```bash
export PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python
```

before building the project.
To build the examples:

```bash
$ bazel build //python_ignition:all
$ bazel build //python_ignition/python:all
```

