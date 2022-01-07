# Python Ignition

Examples using Ignition with the Bazel build system.

## Summary

The table below summarised which projects build on macOS and the repos and branches used.

| library | repo | branch | build | test |
| --- | --- | --- | --- | --- |
|ign-bazel|https://github.com/srmainwaring/ign-bazel|bazel-macos|pass|pass|
|ign-math|https://github.com/srmainwaring/ign-math|bazel-macos/ign-math6|pass|pass|
|ign-utils|https://github.com/ignitionrobotics/ign-utils|main|pass|pass|
|ign-common|https://github.com/srmainwaring/ign-common|bazel-macos/ign-common3|pass|pass|
|ign-msgs|https://github.com/ignitionrobotics/ign-msgs|ign-msgs6|pass|pass|
|sdformat|https://github.com/ignitionrobotics/sdformat| bazel-sdf10|pass|pass|
|ign-plugin|https://github.com/srmainwaring/ign-plugin|bazel-macos/ign-plugin1|pass|pass|
|ign-transport|https://github.com/srmainwaring/ign-transport|bazel-macos/ign-transport9|pass|1 fail|
|ign-physics|https://github.com/ignitionrobotics/ign-physics|bazel-physics3|pass|pass|
|ign-tools|https://github.com/ignitionrobotics/ign-tools|bazel-tools1|partial|-|
|ign-rendering|https://github.com/ignitionrobotics/ign-rendering|bazel-rendering4|fail|fail|
|ign-gui|https://github.com/ignitionrobotics/ign-gui|bazel-gui4|fail|fail|
|ign-sensors|https://github.com/ignitionrobotics/ign-sensors|bazel-sensors4|fail|fail|
|ign-gazebo|https://github.com/ignitionrobotics/ign-gazebo|bazel-gazebo4|fail|fail|
|

## Install

Not all propjects are building, so the following will not work:

```bash
$ bazel build //...
```

To build the examples:

```bash
$ bazel build //python_ignition:all
$ bazel build //python_ignition/python:all
```

## Usage

To use the `ign` command line tool for view topics:

```bash
$ IGN_CONFIG_PATH=bazel-bin/ign_transport ign topic -l
```

Running examples:

```bash
$ ./bazel-bin/python_ignition/msg_example
@python_ignition//:msg_example
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
$ ./bazel-bin/python_ignition/publisher
Publishing hello on topic [/foo]
Publishing hello on topic [/foo]
Publishing hello on topic [/foo]
```

```bash
$ ./bazel-bin/python_ignition/subscriber
Msg: hello

Msg: hello

Msg: hello
```
