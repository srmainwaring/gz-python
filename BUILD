#———————————————————————————————————————————————————————————————————————
# ign_examples using Bazel builds

#———————————————————————————————————————————————————————————————————————
# Quick check of dependencies on third-party packages

cc_binary(
  name = "deps_check",
  srcs = ["deps_check.cc"],
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
    "msg_example.cc",
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
    "publisher.cc",
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
    "subscriber.cc",
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
    "rover_publisher.cc",
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
    "rover_subscriber.cc",
  ],
  deps = [
    "//ign_math:ign_math",
    "//ign_msgs:ign_msgs",
    "//ign_transport:ign_transport",
    "@com_google_protobuf//:protobuf",
  ],
  visibility = ["//visibility:public"],
)