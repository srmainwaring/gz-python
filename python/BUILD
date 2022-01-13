#———————————————————————————————————————————————————————————————————————
# Python examples
# 
# 
# Notes:
# 
# In py_binary the flag:
# 
#   legacy_create_init = False
# 
# Because there are two `ignition` packages. One coming from @ign-msgs9
# that contains the generated protbuf Python bindings, and the other
# from the pybind11 extension modules. The default behaviour is for Bazel
# to generate empty __init__.py files in all subdirectories under the
# <py_binary.name>.runfiles directory in bazel-bin. In that case only the
# first occurrence of `ignition` on the sys.path will be loaded and an
# attempt to import the other package results in module not found errors.
#
# See the function documentation for `py_binary`: 
# Bazel Python Rules: https://docs.bazel.build/versions/main/be/python.html
# 
# 
#———————————————————————————————————————————————————————————————————————

package(default_visibility = ["//visibility:public"])

#———————————————————————————————————————————————————————————————————————
# ign_msgs_py_deps: list of all the generated Python protobuf libraries
# 
ign_msgs_py_deps = [
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
# import_check
# 
py_binary(
  name = "import_check",
  srcs = ["import_check.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# msgs_example
# 
py_binary(
  name = "msgs_example",
  srcs = ["msgs_example.py"],
  deps = ign_msgs_py_deps,
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# transport_example
# 
py_binary(
  name = "transport_example",
  srcs = ["transport_example.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# publisher
# 
# Example: publishes to topic /foo [ignition.msgs.StringMsg]
# 
py_binary(
  name = "publisher",
  srcs = ["publisher.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# subscriber
# 
# Example: subscribes to topic /foo [ignition.msgs.StringMsg]
# 
py_binary(
  name = "subscriber",
  srcs = ["subscriber.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
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
    "@com_google_protobuf//:proto_api",
  ],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
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
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# pub_all_msg_types
# 
py_binary(
  name = "pub_all_msg_types",
  srcs = ["pub_all_msg_types.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_list
# 
# Replicates command: ign topic -l
# 
py_binary(
  name = "ign_topic_list",
  srcs = ["ign_topic_list.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_info
# 
# Replicates command: ign topic -i -t /topic
# 
py_binary(
  name = "ign_topic_info",
  srcs = ["ign_topic_info.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

#———————————————————————————————————————————————————————————————————————
# ign_topic_echo
# 
# Note: this can only echo messages included in the deps = [] 
# 
py_binary(
  name = "ign_topic_echo",
  srcs = ["ign_topic_echo.py"],
  deps = ign_msgs_py_deps + ["//python_ignition:ignition_py"],
  legacy_create_init = False,
)

