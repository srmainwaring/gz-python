#———————————————————————————————————————————————————————————————————————
# Python examples

py_binary(
  name = "msgs_example",
  srcs = ["msgs_example.py"],
  data = [
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:header_py_pb2",
    "@ign-msgs9//:cmd_vel2d_py_pb2",
    "@ign-msgs9//:double_py_pb2",
    "@ign-msgs9//:double_v_py_pb2",
    "@ign-msgs9//:float_py_pb2",
    "@ign-msgs9//:float_v_py_pb2",
    "@ign-msgs9//:pid_py_pb2",
    "@ign-msgs9//:pose_py_pb2",
    "@ign-msgs9//:pose_v_py_pb2",
    "@ign-msgs9//:quaternion_py_pb2",
    "@ign-msgs9//:time_py_pb2",
    "@ign-msgs9//:twist_py_pb2",
    "@ign-msgs9//:vector3d_py_pb2",
    "@ign-msgs9//:wrench_py_pb2",
    "@ign-msgs9//:publish_py_pb2",
    "@ign-msgs9//:publishers_py_pb2",
    "@ign-msgs9//:subscribe_py_pb2",
    "@ign-msgs9//:topic_info_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "transport_example",
  srcs = ["transport_example.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:header_py_pb2",
    "@ign-msgs9//:pose_py_pb2",
    "@ign-msgs9//:quaternion_py_pb2",
    "@ign-msgs9//:time_py_pb2",
    "@ign-msgs9//:twist_py_pb2",
    "@ign-msgs9//:vector3d_py_pb2",
    "@ign-msgs9//:wrench_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "publisher",
  srcs = ["publisher.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:stringmsg_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "subscriber",
  srcs = ["subscriber.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:stringmsg_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "rover_publisher",
  srcs = ["rover_publisher.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:header_py_pb2",
    "@ign-msgs9//:pose_py_pb2",
    "@ign-msgs9//:quaternion_py_pb2",
    "@ign-msgs9//:time_py_pb2",
    "@ign-msgs9//:twist_py_pb2",
    "@ign-msgs9//:vector3d_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "rover_subscriber",
  srcs = ["rover_subscriber.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:header_py_pb2",
    "@ign-msgs9//:pose_py_pb2",
    "@ign-msgs9//:quaternion_py_pb2",
    "@ign-msgs9//:time_py_pb2",
    "@ign-msgs9//:twist_py_pb2",
    "@ign-msgs9//:vector3d_py_pb2",
  ],
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————

py_binary(
  name = "ign_topic_list",
  srcs = ["ign_topic_list.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
  ],
  visibility = ["//visibility:public"],
)

py_binary(
  name = "ign_topic_info",
  srcs = ["ign_topic_info.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
  ],
  visibility = ["//visibility:public"],
)

