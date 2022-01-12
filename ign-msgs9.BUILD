#———————————————————————————————————————————————————————————————————————
# BUILD file for ign-msgs9
#
# Using https://rules-proto-grpc.com
#
# C++
# https://rules-proto-grpc.com/en/latest/example.html
#
# Python 
# https://rules-proto-grpc.com/en/latest/lang/python.html
#
# Notes: python_proto_library
#  - Use output_mode = "NO_PREFIX" to use only the protobuf
#    import path ignition.msgs. The default PREFIX will place
#    each Python protobuf library under an extra folder with
#    the target name.
#
# TODO(srmainwaring):
#     Create a macro to generate the libraries for each .proto
#     Main challenge will be to extract the deps
#

load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@rules_proto_grpc//python:defs.bzl", "python_proto_library")

package(default_visibility = ["//visibility:public"])

#———————————————————————————————————————————————————————————————————————
# proto_files

# load("@ign-msgs9//:protobuf.bzl",
#   "get_include_directory",
#   "proto_path_to_generated_filename",
# )

# load("@//:rules.bzl", "strip_proto_extension")

# get all .proto files
# proto_srcs = glob([
#   "proto/ignition/msgs/*.proto",
# ])

# proto_srcs = [
#   "proto/ignition/msgs/any.proto",
# ]

# deps = get_include_directory(proto_srcs[0])

# test rule name generation
# [genrule(
#     name = proto_path_to_generated_filename(src, "{}_proto2"),
#     srcs = [src],
#     outs = [],
#     cmd = "",
#  ) for src in proto_srcs]

#———————————————————————————————————————————————————————————————————————
# any.proto
proto_library(
  name = "any_proto",
  srcs = ["proto/ignition/msgs/any.proto"],
  deps = [
    ":header_proto",
    ":color_proto",
    ":pose_proto",
    ":quaternion_proto",
    ":time_proto",
    ":vector3d_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "any_cc_proto",
  protos = [":any_proto"],
  deps = [
    ":header_cc_proto",
    ":color_cc_proto",
    ":pose_cc_proto",
    ":quaternion_cc_proto",
    ":time_cc_proto",
    ":vector3d_cc_proto",
  ],
)

python_proto_library(
  name = "any_py_pb2",
  protos = [":any_proto"],
  deps = [
    ":header_py_pb2",
    ":color_py_pb2",
    ":pose_py_pb2",
    ":quaternion_py_pb2",
    ":time_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)


#———————————————————————————————————————————————————————————————————————
# color.proto
proto_library(
  name = "color_proto",
  srcs = ["proto/ignition/msgs/color.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "color_cc_proto",
  protos = [":color_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "color_py_pb2",
  protos = [":color_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# cmd_vel2d.proto
proto_library(
  name = "cmd_vel2d_proto",
  srcs = ["proto/ignition/msgs/cmd_vel2d.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "cmd_vel2d_cc_proto",
  protos = [":cmd_vel2d_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "cmd_vel2d_py_pb2",
  protos = [":cmd_vel2d_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# double.proto
proto_library(
  name = "double_proto",
  srcs = ["proto/ignition/msgs/double.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "double_cc_proto",
  protos = [":double_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "double_py_pb2",
  protos = [":double_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# double_v.proto
proto_library(
  name = "double_v_proto",
  srcs = ["proto/ignition/msgs/double_v.proto"],
  deps = [
    ":double_proto",
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "double_v_cc_proto",
  protos = [":double_v_proto"],
  deps = [
    ":double_cc_proto",
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "double_v_py_pb2",
  protos = [
    ":double_v_proto",
  ],
  deps = [
    ":double_py_pb2",
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# float.proto
proto_library(
  name = "float_proto",
  srcs = ["proto/ignition/msgs/float.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "float_cc_proto",
  protos = [":float_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "float_py_pb2",
  protos = [":float_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# float_v.proto
proto_library(
  name = "float_v_proto",
  srcs = ["proto/ignition/msgs/float_v.proto"],
  deps = [
    ":float_proto",
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "float_v_cc_proto",
  protos = [":float_v_proto"],
  deps = [
    ":float_cc_proto",
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "float_v_py_pb2",
  protos = [":float_v_proto"],
  deps = [
    ":float_py_pb2",
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# header.proto
proto_library(
  name = "header_proto",
  srcs = ["proto/ignition/msgs/header.proto"],
  deps = [":time_proto"],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "header_cc_proto",
  protos = [":header_proto"],
  deps = [
    ":time_cc_proto",
  ],
)

python_proto_library(
  name = "header_py_pb2",
  protos = [":header_proto"],
  deps = [
    ":time_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# param.proto
proto_library(
  name = "param_proto",
  srcs = ["proto/ignition/msgs/param.proto"],
  deps = [
    ":any_proto",
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "param_cc_proto",
  protos = [":param_proto"],
  deps = [
    ":any_cc_proto",
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "param_py_pb2",
  protos = [":param_proto"],
  deps = [
    ":any_py_pb2",
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# pid.proto
proto_library(
  name = "pid_proto",
  srcs = ["proto/ignition/msgs/pid.proto"],
  deps = [
    ":double_proto",
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "pid_cc_proto",
  protos = [":pid_proto"],
  deps = [
    ":double_cc_proto",
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "pid_py_pb2",
  protos = [":pid_proto"],
  deps = [
    ":double_py_pb2",
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# pose.proto
proto_library(
  name = "pose_proto",
  srcs = ["proto/ignition/msgs/pose.proto"],
  deps = [
    ":header_proto",
    ":quaternion_proto",
    ":vector3d_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "pose_cc_proto",
  protos = [":pose_proto"],
  deps = [
    ":header_cc_proto",
    ":quaternion_cc_proto",
    ":vector3d_cc_proto",
  ],
)

python_proto_library(
  name = "pose_py_pb2",
  protos = [":pose_proto"],
  deps = [
    ":header_py_pb2",
    ":quaternion_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# pose_v.proto
proto_library(
  name = "pose_v_proto",
  srcs = ["proto/ignition/msgs/pose_v.proto"],
  deps = [
    ":header_proto",
    ":pose_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "pose_v_cc_proto",
  protos = [":pose_v_proto"],
  deps = [
    ":header_cc_proto",
    ":pose_cc_proto",
  ],
)

python_proto_library(
  name = "pose_v_py_pb2",
  protos = [":pose_v_proto"],
  deps = [
    ":header_py_pb2",
    ":pose_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# publish.proto
proto_library(
  name = "publish_proto",
  srcs = ["proto/ignition/msgs/publish.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "publish_cc_proto",
  protos = [":publish_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "publish_py_pb2",
  protos = [":publish_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# publishers.proto
proto_library(
  name = "publishers_proto",
  srcs = ["proto/ignition/msgs/publishers.proto"],
  deps = [
    ":header_proto",
    ":publish_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "publishers_cc_proto",
  protos = [":publishers_proto"],
  deps = [
    ":header_cc_proto",
    ":publish_cc_proto",
  ],
)

python_proto_library(
  name = "publishers_py_pb2",
  protos = [":publishers_proto"],
  deps = [
    ":header_py_pb2",
    ":publish_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# quaternion.proto
proto_library(
  name = "quaternion_proto",
  srcs = ["proto/ignition/msgs/quaternion.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "quaternion_cc_proto",
  protos = [":quaternion_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "quaternion_py_pb2",
  protos = [":quaternion_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# stringmsg.proto
proto_library(
  name = "stringmsg_proto",
  srcs = ["proto/ignition/msgs/stringmsg.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "stringmsg_cc_proto",
  protos = [":stringmsg_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "stringmsg_py_pb2",
  protos = [":stringmsg_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# subscribe.proto
proto_library(
  name = "subscribe_proto",
  srcs = ["proto/ignition/msgs/subscribe.proto"],
  deps = [
    ":header_proto"
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "subscribe_cc_proto",
  protos = [":subscribe_proto"],
  deps = [
    ":header_cc_proto"
  ],
)

python_proto_library(
  name = "subscribe_py_pb2",
  protos = [":subscribe_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# time.proto
proto_library(
  name = "time_proto",
  srcs = ["proto/ignition/msgs/time.proto"],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "time_cc_proto",
  protos = [":time_proto"],
)

python_proto_library(
  name = "time_py_pb2",
  protos = [":time_proto"],
  output_mode = "NO_PREFIX",
 )

#———————————————————————————————————————————————————————————————————————
# topic_info.proto
proto_library(
  name = "topic_info_proto",
  srcs = ["proto/ignition/msgs/topic_info.proto"],
  deps = [
    ":header_proto",
    ":publish_proto",
    ":subscribe_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "topic_info_cc_proto",
  protos = [":topic_info_proto"],
  deps = [
    ":header_cc_proto",
    ":publish_cc_proto",
    ":subscribe_cc_proto",
  ],
)

python_proto_library(
  name = "topic_info_py_pb2",
  protos = [":topic_info_proto"],
  deps = [
    ":header_py_pb2",
    ":publish_py_pb2",
    ":subscribe_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# twist.proto
proto_library(
  name = "twist_proto",
  srcs = ["proto/ignition/msgs/twist.proto"],
  deps = [
    ":header_proto",
    ":vector3d_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "twist_cc_proto",
  protos = [":twist_proto"],
  deps = [
    ":header_cc_proto",
    ":vector3d_cc_proto",
  ],
)

python_proto_library(
  name = "twist_py_pb2",
  protos = [":twist_proto"],
  deps = [
    ":header_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# vector3d.proto
proto_library(
  name = "vector3d_proto",
  srcs = ["proto/ignition/msgs/vector3d.proto"],
  deps = [
    ":header_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "vector3d_cc_proto",
  protos = [":vector3d_proto"],
  deps = [
    ":header_cc_proto",
  ],
)

python_proto_library(
  name = "vector3d_py_pb2",
  protos = [":vector3d_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)

#———————————————————————————————————————————————————————————————————————
# wrench.proto
proto_library(
  name = "wrench_proto",
  srcs = ["proto/ignition/msgs/wrench.proto"],
  deps = [
    ":header_proto",
    ":vector3d_proto",
  ],
  strip_import_prefix = "proto",
)

cpp_proto_library(
  name = "wrench_cc_proto",
  protos = [":wrench_proto"],
  deps = [
    ":header_cc_proto",
    ":vector3d_cc_proto",
  ],
)

python_proto_library(
  name = "wrench_py_pb2",
  protos = [":wrench_proto"],
  deps = [
    ":header_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
)
