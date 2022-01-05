# Python Ignition

This project aims to provide Python bindings for [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) and [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport). It is a work in progress...

C++ and Python libraries for [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) are generated using [Protobuf and gRPC rules for Bazel](https://rules-proto-grpc.com/en/latest/index.html).

The objective is to generate Python bindings for [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport) using [`pybind11`](https://github.com/pybind/pybind11). Interoperability between native Python protobuf
libraries and the C++ protobuf library used in the [`pybind11`](https://github.com/pybind/pybind11) extension module is provided by [`pybind11_protobuf`](https://github.com/pybind/pybind11_protobuf).

### Status

- Working bindings for a selection of [`ignition-msgs`](https://github.com/ignitionrobotics/ign-msgs) are available using the protocol buffers native Python implementation. The build rules for the C++ implementation are also available however there is an open issue in [`pybind11_protobuf`](https://github.com/pybind/pybind11_protobuf) that prevents full interoperability in this case (see Notes below).
- Bindings for [`ignition-transport`](https://github.com/ignitionrobotics/ign-transport) are in development. A mock-up of the main interfaces is provided that illustrates the proposed approach.

## Install: macOS

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

Build everything

```bash
$ bazel build //...
```

## Usage

The Bazel build file `ign-msgs8=9.BUILD` defines targets for a selection of messages.
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

There are C++ and Python examples:

- `src/main.cc` an example using the C++ protobuf library.
- `python/ign_proto_example` an example using the Python protobuf library.
- `python/ign_msgs_example` an example using the Python protobuf library and a simple extenson module with functions that accept and return `ignition-msgs`.
- `python/ign_transport_example` an example using the Python protobuf library and an
extenson module with a mock-up of the `ignition.transport::Node` interface.

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
