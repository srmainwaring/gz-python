# Ignition Bazel Examples

This project contains copies of the tutorial examples and Bazel `BUILD` files
to compile them.


| repo | build | test |
| --- | --- | --- |
| ign-utils | | |
| ign-maths | | |
| ign-msgs | | |
| ign-common | | |
| sdformat | | |
| ign-plugin  | | |
| ign-physics | | |
| ign-transport | | |
| ign-fuel_tools | | |
| ign-rendering | | |
| ign-gui | | |
| ign-sensors | | |
| ign-gazebo | | |

## `ign-bazel` macOS

| repo | branch |
| --- | --- |
| https://github.com/srmainwaring/ign-bazel         | bazel-macos |
| https://github.com/srmainwaring/ign-common        | bazel-macos/ign-common3 |
| https://github.com/srmainwaring/ign-math          | bazel-macos/ign-math6 |
| https://github.com/srmainwaring/ign-math          | bazel-macos/ign-math6 |
| https://github.com/ignitionrobotics/ign-msgs      | ign-msgs6 |
| https://github.com/ignitionrobotics/ign-physics   | bazel-physics3 |
| https://github.com/srmainwaring/ign-plugin        | bazel-macos/ign-plugin1 |
| https://github.com/ignitionrobotics/ign-tools     | bazel-tools1 |
| https://github.com/srmainwaring/ign-transport     | bazel-macos/ign-transport9 |
| https://github.com/ignitionrobotics/ign-utils     | main |
| https://github.com/ignitionrobotics/sdformat      | bazel-sdf10 |


## Install

```bash
$ bazel build //...
```

Using `ign` command line tool:

```bash
$ IGN_CONFIG_PATH=bazel-bin/ign_transport ign -h
```

Running examples:

```bash
$ ./bazel-bin/ign_examples/msg_example
@ign_examples//:msg_example
Point1:
x: 1
y: 3
z: 5

Point2:
x: 2
y: 4
z: 6
```

```bash
$ ./bazel-bin/ign_examples/publisher
Publishing hello on topic [/foo]
Publishing hello on topic [/foo]
Publishing hello on topic [/foo]
```

```bash
$ ./bazel-bin/ign_examples/subscriber
Msg: hello

Msg: hello

Msg: hello
```
