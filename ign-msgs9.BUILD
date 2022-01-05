#------------------------------------------------
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

# load("@com_github_grpc_grpc//bazel:python_rules.bzl", "python_proto_library")
# load("@com_google_protobuf//:protobuf.bzl", "python_proto_library")

load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@rules_proto_grpc//python:defs.bzl", "python_proto_library")

#------------------------------------------------
# time.proto
proto_library(
  name = "time_proto",
  srcs = ["ignition/msgs/time.proto"],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "time_cc_proto",
  protos = [":time_proto"],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "time_py_pb2",
  protos = [":time_proto"],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
 )

#------------------------------------------------
# header.proto
proto_library(
  name = "header_proto",
  srcs = ["ignition/msgs/header.proto"],
  deps = [":time_proto"],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "header_cc_proto",
  protos = [":header_proto"],
  deps = [
    ":time_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "header_py_pb2",
  protos = [":header_proto"],
  deps = [
    ":time_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# cmd_vel2d.proto
proto_library(
  name = "cmd_vel2d_proto",
  srcs = ["ignition/msgs/cmd_vel2d.proto"],
  deps = [
    ":header_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "cmd_vel2d_cc_proto",
  protos = [":cmd_vel2d_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "cmd_vel2d_py_pb2",
  protos = [":cmd_vel2d_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# double.proto
proto_library(
  name = "double_proto",
  srcs = ["ignition/msgs/double.proto"],
  deps = [
    ":header_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "double_cc_proto",
  protos = [":double_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "double_py_pb2",
  protos = [":double_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

# #------------------------------------------------
# double_v.proto
proto_library(
  name = "double_v_proto",
  srcs = ["ignition/msgs/double_v.proto"],
  deps = [
    ":header_proto",
    ":double_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "double_v_cc_proto",
  protos = [":double_v_proto"],
  deps = [
    ":header_cc_proto",
    ":double_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "double_v_py_pb2",
  protos = [
    ":double_v_proto",
  ],
  deps = [
    ":header_py_pb2",
    ":double_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# float.proto
proto_library(
  name = "float_proto",
  srcs = ["ignition/msgs/float.proto"],
  deps = [
    ":header_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "float_cc_proto",
  protos = [":float_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "float_py_pb2",
  protos = [":float_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# float_v.proto
proto_library(
  name = "float_v_proto",
  srcs = ["ignition/msgs/float_v.proto"],
  deps = [
    ":header_proto",
    ":float_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "float_v_cc_proto",
  protos = [":float_v_proto"],
  deps = [
    ":header_cc_proto",
    ":float_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "float_v_py_pb2",
  protos = [":float_v_proto"],
  deps = [
    ":header_py_pb2",
    ":float_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# pid.proto
proto_library(
  name = "pid_proto",
  srcs = ["ignition/msgs/pid.proto"],
  deps = [
    ":header_proto",
    ":double_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "pid_cc_proto",
  protos = [":pid_proto"],
  deps = [
    ":header_cc_proto",
    ":double_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "pid_py_pb2",
  protos = [":pid_proto"],
  deps = [
    ":header_py_pb2",
    ":double_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# quaternion.proto
proto_library(
  name = "quaternion_proto",
  srcs = ["ignition/msgs/quaternion.proto"],
  deps = [
    ":header_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "quaternion_cc_proto",
  protos = [":quaternion_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "quaternion_py_pb2",
  protos = [":quaternion_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# vector3d.proto
proto_library(
  name = "vector3d_proto",
  srcs = ["ignition/msgs/vector3d.proto"],
  deps = [
    ":header_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "vector3d_cc_proto",
  protos = [":vector3d_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "vector3d_py_pb2",
  protos = [":vector3d_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# pose.proto
proto_library(
  name = "pose_proto",
  srcs = ["ignition/msgs/pose.proto"],
  deps = [
    ":header_proto",
    ":quaternion_proto",
    ":vector3d_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "pose_cc_proto",
  protos = [":pose_proto"],
  deps = [
    ":header_cc_proto",
    ":quaternion_cc_proto",
    ":vector3d_cc_proto",
  ],
  visibility = ["//visibility:public"],
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
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# pose_v.proto
proto_library(
  name = "pose_v_proto",
  srcs = ["ignition/msgs/pose_v.proto"],
  deps = [
    ":header_proto",
    ":pose_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "pose_v_cc_proto",
  protos = [":pose_v_proto"],
  deps = [
    ":header_cc_proto",
    ":pose_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "pose_v_py_pb2",
  protos = [":pose_v_proto"],
  deps = [
    ":header_py_pb2",
    ":pose_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# twist.proto
proto_library(
  name = "twist_proto",
  srcs = ["ignition/msgs/twist.proto"],
  deps = [
    ":header_proto",
    ":vector3d_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "twist_cc_proto",
  protos = [":twist_proto"],
  deps = [
    ":header_cc_proto",
    ":vector3d_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "twist_py_pb2",
  protos = [":twist_proto"],
  deps = [
    ":header_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# wrench.proto
proto_library(
  name = "wrench_proto",
  srcs = ["ignition/msgs/wrench.proto"],
  deps = [
    ":header_proto",
    ":vector3d_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "wrench_cc_proto",
  protos = [":wrench_proto"],
  deps = [
    ":header_cc_proto",
    ":vector3d_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "wrench_py_pb2",
  protos = [":wrench_proto"],
  deps = [
    ":header_py_pb2",
    ":vector3d_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# publish.proto
proto_library(
    name = "publish_proto",
    srcs = ["ignition/msgs/publish.proto"],
    deps = [
      ":header_proto",
    ],
    visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "publish_cc_proto",
  protos = [":publish_proto"],
  deps = [
    ":header_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "publish_py_pb2",
  protos = [":publish_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# publishers.proto
proto_library(
  name = "publishers_proto",
  srcs = ["ignition/msgs/publishers.proto"],
  deps = [
    ":header_proto",
    ":publish_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "publishers_cc_proto",
  protos = [":publishers_proto"],
  deps = [
    ":header_cc_proto",
    ":publish_cc_proto",
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "publishers_py_pb2",
  protos = [":publishers_proto"],
  deps = [
    ":header_py_pb2",
    ":publish_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# subscribe.proto
proto_library(
  name = "subscribe_proto",
  srcs = ["ignition/msgs/subscribe.proto"],
  deps = [
    ":header_proto"
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "subscribe_cc_proto",
  protos = [":subscribe_proto"],
  deps = [
    ":header_cc_proto"
  ],
  visibility = ["//visibility:public"],
)

python_proto_library(
  name = "subscribe_py_pb2",
  protos = [":subscribe_proto"],
  deps = [
    ":header_py_pb2",
  ],
  output_mode = "NO_PREFIX",
  visibility = ["//visibility:public"],
)

#------------------------------------------------
# topic_info.proto
proto_library(
  name = "topic_info_proto",
  srcs = ["ignition/msgs/topic_info.proto"],
  deps = [
    ":header_proto",
    ":publish_proto",
    ":subscribe_proto",
  ],
  visibility = ["//visibility:public"],
)

cpp_proto_library(
  name = "topic_info_cc_proto",
  protos = [":topic_info_proto"],
  deps = [
    ":header_cc_proto",
    ":publish_cc_proto",
    ":subscribe_cc_proto",
  ],
  visibility = ["//visibility:public"],
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
  visibility = ["//visibility:public"],
)
