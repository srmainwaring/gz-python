/*
 * Copyright (C) 2022 Rhys Mainwaring
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <iostream>
#include <string>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>

void cb(const google::protobuf::Message &_msg)
{
  std::cout << _msg.DebugString() << std::endl;
}

void print_usage()
{
  std::cout << "Must supply topic using '-t' or '--topic'" << std::endl;
}

void print_missing_topic()
{
  std::cout << "Must supply a valid topic" << std::endl;
}

int main(int argc, char **argv)
{
  ignition::transport::Node node;

  // parse arguments: expect either '-t /topic' or '--topic /topic'
  std::string topic = "";
  if (argc > 1)
  {
    std::string arg(argv[1]);
    if (arg.compare("-t") != 0 && arg.compare("--topic") != 0)
    {
      print_usage();
      return -1;
    }
  }
  if (argc > 2)
  {
    topic = argv[2];
  }
  else
  {
    print_missing_topic();
    return -1;
  }

  // Subscribe to a topic by registering a callback.
  if (!node.Subscribe(topic, cb))
  {
    std::cerr << "Error subscribing to topic [" << topic << "]" << std::endl;
    return -1;
  }

  ignition::transport::waitForShutdown();
  return 0;
}