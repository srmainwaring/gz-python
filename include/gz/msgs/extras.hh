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

#ifndef GZ_PYTHON_MSGS_HH
#define GZ_PYTHON_MSGS_HH

#include <gz/msgs/time.pb.h>
#include <gz/msgs/topic_info.pb.h>
#include <gz/msgs/wrench.pb.h>

namespace gz
{
namespace msgs
{
namespace extras
{

  Time MakeTime();

  void TakeTime(const Time& msg);

  void TakeTopicInfo(const TopicInfo& msg);

  void TakeWrench(const Wrench& msg);
}  // extras
}  // msgs
}  // gz

#endif  // GZ_PYTHON_MSGS_HH
