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

import time

from gz.msgs.pid_pb2 import PID

from gz.transport import Node

# service response callback
def rep_cb(msg, result):
    print("Result: {}".format(result))
    print("Response: {}".format(msg))

def main():
    # create a transport node
    node = Node()
    service = "/model/iris_with_ardupilot/"\
              "joint/iris_with_standoffs::rotor_0_joint/pid"
    req_type_name = PID.DESCRIPTOR.full_name
    rep_type_name = PID.DESCRIPTOR.full_name

    # populate PID message
    req = PID()
    req.p_gain_optional.data = 0.2
    req.i_gain_optional.data = 0.0
    req.d_gain_optional.data = 0.0
    req.i_max_optional.data = 1.0
    req.i_min_optional.data = -1.0
    req.limit_optional.data = 10.0

    # timeout in ms
    timeout = 1000

    # call service (blocking)
    print("Blocking service call")
    executed, result = node.request(service, req, timeout, rep_type_name)

    # update PID so we can verify second call
    req.p_gain_optional.data = 0.3

    # call service (non-blocking)
    print("Non-blocking service call")
    executed = node.request(service, req, rep_cb, rep_type_name)

    # wait for response before exiting
    time.sleep(timeout/1000)
    print("Done")

if __name__ == "__main__":
    main()

