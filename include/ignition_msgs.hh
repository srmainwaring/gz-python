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

#ifndef PYTHON_IGNITION_MSGS_HH
#define PYTHON_IGNITION_MSGS_HH

#include "ignition/msgs/time.pb.h"
#include "ignition/msgs/topic_info.pb.h"
#include "ignition/msgs/wrench.pb.h"

ignition::msgs::Time MakeTime();

void TakeTime(const ignition::msgs::Time& msg);

void TakeTopicInfo(const ignition::msgs::TopicInfo& msg);

void TakeWrench(const ignition::msgs::Wrench& msg);

#endif