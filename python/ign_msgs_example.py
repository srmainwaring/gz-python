#!/user/bin/env python

# Copyright (C) 2022 Rhys Mainwaring
#
# Licensed under the Apache License, Version 2.0 (the "License")
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http:#www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ignition.msgs.header_pb2 import Header
from ignition.msgs.time_pb2 import Time
from ignition.msgs.vector3d_pb2 import Vector3d
from ignition.msgs.wrench_pb2 import Wrench

from ignition.msgs.publish_pb2 import Publish
from ignition.msgs.publishers_pb2 import Publishers
from ignition.msgs.subscribe_pb2 import Subscribe
from ignition.msgs.topic_info_pb2 import TopicInfo

import ignition_msgs

from google.protobuf.internal import api_implementation

def main():
  print("Ignition Messages Example\n")

  #----------------------------------------------
  # google.protobuf implementation
  print("proto api type: {}".format(api_implementation.Type()))

  print("----------------------------------------")
  time_msg = Time()
  time_msg.sec = 15
  time_msg.nsec = 21
  print(type(time_msg))
  print("isinstance: {}".format(isinstance(time_msg, Time)))
  ignition_msgs.take_time(time_msg)

  # TODO: failing with use_fast_cpp_proto because isinstance is failing
  #       for cpp wrapped protobuf.
  #       See: https://github.com/pybind/pybind11_protobuf/issues/44
  # print("----------------------------------------")
  # time_msg = ignition_msgs.make_time()
  # print(type(time_msg))
  # print("isinstance: {}".format(isinstance(time_msg, Time)))
  # ignition_msgs.take_time(time_msg)

  print("----------------------------------------")
  header_msg = Header()
  header_msg.stamp.CopyFrom(time_msg)  
  print(type(header_msg))
  # print(header_msg)

  print("----------------------------------------")
  vector3d_msg = Vector3d()
  vector3d_msg.header.CopyFrom(header_msg)
  vector3d_msg.x = 21.3
  vector3d_msg.y = 12.7
  vector3d_msg.z = 15.2
  print(type(vector3d_msg))
  # print(vector3d_msg)

  print("----------------------------------------")
  wrench_msg = Wrench()
  wrench_msg.header.CopyFrom(header_msg)
  wrench_msg.force.CopyFrom(vector3d_msg)
  wrench_msg.torque.CopyFrom(vector3d_msg)
  wrench_msg.force_offset.CopyFrom(vector3d_msg)
  print(type(wrench_msg))
  # print(wrench_msg)
  ignition_msgs.take_wrench(wrench_msg)

  print("----------------------------------------")
  pub_msg = Publish()
  pub_msg.header.CopyFrom(header_msg)
  pub_msg.topic = "/force_torque"
  pub_msg.msg_type = "ignition.msgs.Wrench"
  pub_msg.host = "127.0.0.1"
  pub_msg.port = 11311
  print(type(pub_msg))
  # print(pub_msg)

  print("----------------------------------------")
  sub_msg = Subscribe()
  sub_msg.header.CopyFrom(header_msg)
  sub_msg.topic = "/force_torque"
  sub_msg.msg_type = "ignition.msgs.Wrench"
  sub_msg.host = "127.0.0.1"
  sub_msg.port = 11311
  sub_msg.latching = True
  print(type(sub_msg))
  # print(sub_msg)

  print("----------------------------------------")
  topic_msg = TopicInfo()
  topic_msg.header.CopyFrom(header_msg)
  topic_msg.msg_type = "ignition.msgs.Wrench"
  topic_msg.publisher.append(pub_msg)
  topic_msg.subscriber.append(sub_msg)
  print(type(topic_msg))
  # print(topic_msg)
  ignition_msgs.take_topic_info(topic_msg)


if __name__ == "__main__":
  main()
