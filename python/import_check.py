#!/usr/bin/env python

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

import time

from ignition.msgs.any_pb2 import Any
from ignition.msgs.header_pb2 import Header
from ignition.msgs.stringmsg_pb2 import StringMsg

from ignition.msgs.extras import make_time
from ignition.msgs.extras import take_time
from ignition.msgs.extras import take_topic_info
from ignition.msgs.extras import take_wrench

from ignition.transport import AdvertiseMessageOptions
from ignition.transport import Node


def main():
    # msgs
    msg = Any()
    msg = Header()
    msg = StringMsg()

    # msgs functions
    msg = make_time()

    # transport types
    opts = AdvertiseMessageOptions()
    node = Node()
    pub = Node.Publisher()


if __name__ == "__main__":
    main()
