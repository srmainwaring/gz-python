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

#include "gz/msgs/extras.hh"

#include <pybind11/pybind11.h>

#include "pybind11_protobuf/native_proto_caster.h"

namespace py = pybind11;

PYBIND11_MODULE(extras, m)
{
  using namespace gz;
  using namespace msgs;
  using namespace extras;

  pybind11_protobuf::ImportNativeProtoCasters();

  m.doc() = "Gazebo Msgs Extras Python Library.";

  m.def("make_time", &MakeTime);
  m.def("take_time", &TakeTime, pybind11::arg("msg"));
  m.def("take_topic_info", &TakeTopicInfo, pybind11::arg("msg"));
  m.def("take_wrench", &TakeWrench, pybind11::arg("msg"));
}
