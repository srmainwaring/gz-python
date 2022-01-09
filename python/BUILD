#———————————————————————————————————————————————————————————————————————
# Python examples
#———————————————————————————————————————————————————————————————————————

#———————————————————————————————————————————————————————————————————————
# ign_msg_py_deps: list of all the generated Python protobuf libraries
# 
ign_msg_py_deps = [
  "@ign-msgs9//:any_py_pb2",
  "@ign-msgs9//:color_py_pb2",
  "@ign-msgs9//:cmd_vel2d_py_pb2",
  "@ign-msgs9//:double_py_pb2",
  "@ign-msgs9//:double_v_py_pb2",
  "@ign-msgs9//:float_py_pb2",
  "@ign-msgs9//:float_v_py_pb2",
  "@ign-msgs9//:header_py_pb2",
  "@ign-msgs9//:param_py_pb2",
  "@ign-msgs9//:pid_py_pb2",
  "@ign-msgs9//:pose_py_pb2",
  "@ign-msgs9//:pose_v_py_pb2",
  "@ign-msgs9//:publish_py_pb2",
  "@ign-msgs9//:publishers_py_pb2",
  "@ign-msgs9//:quaternion_py_pb2",
  "@ign-msgs9//:stringmsg_py_pb2",
  "@ign-msgs9//:subscribe_py_pb2",
  "@ign-msgs9//:time_py_pb2",
  "@ign-msgs9//:topic_info_py_pb2",
  "@ign-msgs9//:twist_py_pb2",
  "@ign-msgs9//:vector3d_py_pb2",
  "@ign-msgs9//:wrench_py_pb2",
]

#———————————————————————————————————————————————————————————————————————
# msgs_example
# 
py_binary(
  name = "msgs_example",
  srcs = ["msgs_example.py"],
  data = [
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# transport_example
# 
py_binary(
  name = "transport_example",
  srcs = ["transport_example.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# publisher
# 
# Example: publishes to topic /foo [ignition.msgs.StringMsg]
# 
py_binary(
  name = "publisher",
  srcs = ["publisher.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# subscriber
# 
# Example: subscribes to topic /foo [ignition.msgs.StringMsg]
# 
py_binary(
  name = "subscriber",
  srcs = ["subscriber.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# rover_subscriber
# 
# Example: publishes to topics /pose [ignition.msgs.Pose]
#          and /twist [ignition.msgs.Twist]
# 
py_binary(
  name = "rover_publisher",
  srcs = ["rover_publisher.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# rover_subscriber
# 
# Example: subscribes to topics /pose [ignition.msgs.Pose]
#          and /twist [ignition.msgs.Twist]
# 
py_binary(
  name = "rover_subscriber",
  srcs = ["rover_subscriber.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# pub_all_msg_types
# 
py_binary(
  name = "pub_all_msg_types",
  srcs = ["pub_all_msg_types.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_list
# 
# Replicates command: ign topic -l
# 
py_binary(
  name = "ign_topic_list",
  srcs = ["ign_topic_list.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_info
# 
# Replicates command: ign topic -i -t /topic
# 
py_binary(
  name = "ign_topic_info",
  srcs = ["ign_topic_info.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_echo
# 
# Note: this can only echo messages included in the deps = [] 
# 
py_binary(
  name = "ign_topic_echo",
  srcs = ["ign_topic_echo.py"],
  data = [
    "//python_ignition:ignition_transport.so",
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msg_py_deps,
  visibility = ["//visibility:public"],
)

