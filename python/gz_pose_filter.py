#!/usr/bin/env python

# Copyright (C) 2023 Rhys Mainwaring
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

'''
Subscribe to a pose or pose array, filter and republish.
'''

import argparse
import copy
import time

from gz.msgs.pose_pb2 import Pose
from gz.msgs.pose_v_pb2 import Pose_V

from gz.transport import AdvertiseMessageOptions
from gz.transport import SubscribeOptions
from gz.transport import Node

# TODO 
# Summary 
# - Gazebo publishes the pose of entires to
#   /world/<world_name>/dynamic_pose/info.
# - This is a pose vector - we want to filter for specific entries. 
# 
# Requirements 
# 
# 
# Tasks
# - check message type is Pose or Pose_V
# - apply filter
# - republish message to output topic

pose_name = ""
last_pose = Pose()

# callback - capture the filtered last filtered pose
def cb(msg):
    global last_pose

    if msg.DESCRIPTOR.full_name == Pose.DESCRIPTOR.full_name:
        # print("Got {}".format(Pose.DESCRIPTOR.full_name))
        if msg.name == pose_name:
          last_pose.CopyFrom(msg)

    elif msg.DESCRIPTOR.full_name == Pose_V.DESCRIPTOR.full_name:
        # print("Got {}".format(Pose_V.DESCRIPTOR.full_name))
        for pose in msg.pose:
            if pose.name == pose_name:
              last_pose.CopyFrom(pose)
              last_pose.header.CopyFrom(msg.header)

    else:
        print("Message type {} is not {} or {}".format(
            type(msg), Pose.DESCRIPTOR.full_name, Pose_V.DESCRIPTOR.full_name))

def main():
    global pose_name
    global last_pose

    # process command line
    parser = argparse.ArgumentParser(
        description="Apply a filter to a Pose_V.")
    parser.add_argument("-t", "--topic",
        metavar="topic", required=True, help="Name of a topic.")
    parser.add_argument("-n", "--name",
        metavar="name", required=True, help="Name of a pose.")
    parser.add_argument("-o", "--out-topic",
        metavar="out_topic", default="/pose", help="Name of output topic.")
    parser.add_argument("-r", "--update-rate",
        metavar="update_rate", default=50, help="Update rate for output.")
    args = parser.parse_args()

    # topic is required
    topic = args.topic

    # update global pose name for callback
    pose_name = args.name

    # create a transport node
    node = Node()

    msg_type_name = "google.protobuf.Message"
    sub_options = SubscribeOptions()

    # subscribe to a topic by registering a callback
    if node.subscribe(topic, cb, msg_type_name, sub_options):
        print("Subscribing to topic [{}]".format(topic))
    else:
        print("Error subscribing to topic [{}]".format(topic))
        return

    # advertise topic
    pub_options = AdvertiseMessageOptions()
    pose_topic = args.out_topic
    pose_msg_type_name = Pose.DESCRIPTOR.full_name

    pose_pub = node.advertise(
        pose_topic, pose_msg_type_name, pub_options)
    if pose_pub.valid():
        print("Advertising {} on topic [{}]".format(
            pose_msg_type_name, pose_topic))
    else:
        print("Error advertising topic [{}]".format(pose_topic))

    # wait for shutdown
    update_rate = float(args.update_rate)
    update_period_ns = 1.0 / update_rate * 1.0E9

    last_ns = time.time_ns()

    try:
      while True:
        now_ns = time.time_ns()
        if now_ns - last_ns > update_period_ns:
            last_ns = now_ns

            # publish
            pose_pub.publish(last_pose)
            print("Published pose\n{}".format(last_pose))

        time.sleep(0.0001)
    except KeyboardInterrupt:
      pass

if __name__ == "__main__":
    main()

