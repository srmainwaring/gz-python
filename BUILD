#———————————————————————————————————————————————————————————————————————
# ign_examples using Bazel builds

#———————————————————————————————————————————————————————————————————————
# deps_check
# Quick check of dependencies on third-party packages

cc_binary(
  name = "deps_check",
  srcs = ["src/deps_check.cc"],
  deps = [
    "//ign_utils:ign_utils",
    "//ign_math:ign_math",
    "//ign_math:libignition-math6.so",
    "@tinyxml2",
    "@sqlite3",
    "@zmq",
    "@zip",
    "@yaml",
    "@curl",
    "@json",
    "@glib",
    "@gts",
    "@freeimage",
    # "@gl",
    # "@X//:Xaw",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# msg_example

cc_binary(
  name = "msg_example",
  srcs = [
    "src/msg_example.cc",
  ],
  deps = [
    "//ign_msgs:ign_msgs",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# publisher

cc_binary(
  name = "publisher",
  srcs = [
    "src/publisher.cc",
  ],
  deps = [
    "//ign_msgs:ign_msgs",
    "//ign_transport:ign_transport",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# subscriber

cc_binary(
  name = "subscriber",
  srcs = [
    "src/subscriber.cc",
  ],
  deps = [
    "//ign_msgs:ign_msgs",
    "//ign_transport:ign_transport",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# rover_publisher

cc_binary(
  name = "rover_publisher",
  srcs = [
    "src/rover_publisher.cc",
  ],
  deps = [
    "//ign_math:ign_math",
    "//ign_msgs:ign_msgs",
    "//ign_transport:ign_transport",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# rover_subscriber

cc_binary(
  name = "rover_subscriber",
  srcs = [
    "src/rover_subscriber.cc",
  ],
  deps = [
    "//ign_math:ign_math",
    "//ign_msgs:ign_msgs",
    "//ign_transport:ign_transport",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# ignition_transport
# 
# Python bindings for ignition transport

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

pybind_extension(
  name = "ignition_transport",
  srcs = ["src/pybind11/ignition_transport.cc"],
  deps = [
      "//ign_transport:ign_transport",
      "@pybind11_protobuf//pybind11_protobuf:native_proto_caster",
      "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)

