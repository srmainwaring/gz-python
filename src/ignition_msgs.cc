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

#include "ignition_msgs.hh"

ignition::msgs::Time MakeTime()
{
  ignition::msgs::Time msg;
  msg.set_sec(10);
  msg.set_nsec(20);
  return msg;
}

void TakeTime(const ignition::msgs::Time& msg)
{
  std::cout << msg.DebugString();
}

void TakeTopicInfo(const ignition::msgs::TopicInfo& msg)
{
  std::cout << msg.DebugString();
}

void TakeWrench(const ignition::msgs::Wrench& msg)
{
  std::cout << msg.DebugString();
}
