#------------------------------------------------
# Python examples

py_binary(
  name = "ign_proto_example",
  srcs = ["ign_proto_example.py"],
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
)

py_binary(
  name = "ign_msgs_example",
  srcs = ["ign_msgs_example.py"],
  data = [
    "//:ignition_msgs.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = [
    "@ign-msgs9//:header_py_pb2",
    "@ign-msgs9//:time_py_pb2",
    "@ign-msgs9//:vector3d_py_pb2",
    "@ign-msgs9//:wrench_py_pb2",
    "@ign-msgs9//:publish_py_pb2",
    "@ign-msgs9//:publishers_py_pb2",
    "@ign-msgs9//:subscribe_py_pb2",
    "@ign-msgs9//:topic_info_py_pb2",
  ],
)

py_binary(
  name = "ign_transport_example",
  srcs = ["ign_transport_example.py"],
  data = [
    "//:ignition_transport.so",
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
)