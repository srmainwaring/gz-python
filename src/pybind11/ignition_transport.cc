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

#include <ignition/transport.hh>

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include "pybind11_protobuf/native_proto_caster.h"

#include <google/protobuf/message.h>

#include <functional>

namespace py = pybind11;

/// \brief Define pybind11 bindings for ignition::transport objects
void define_transport_node(py::object module)
{
  pybind11_protobuf::ImportNativeProtoCasters();

  using namespace ignition;
  using namespace transport;

  py::class_<AdvertiseMessageOptions>(
      module, "AdvertiseMessageOptions")
      .def(py::init<>())
      .def_property_readonly("throttled",
          &AdvertiseMessageOptions::Throttled)
      .def_property("msgs_per_sec",
          &AdvertiseMessageOptions::MsgsPerSec,
          &AdvertiseMessageOptions::SetMsgsPerSec)
      ;

  py::class_<SubscribeOptions>(
      module, "SubscribeOptions")
      .def(py::init<>())
      .def_property_readonly("throttled",
          &SubscribeOptions::Throttled)
      .def_property("msgs_per_sec",
          &SubscribeOptions::MsgsPerSec,
          &SubscribeOptions::SetMsgsPerSec)
      ;

  py::class_<Node>(module, "Node")
      .def(py::init<>())
      .def("advertise", static_cast<
          Node::Publisher (Node::*) (
              const std::string &,
              const std::string &,
              const AdvertiseMessageOptions &
          )>(&Node::Advertise),
          pybind11::arg("topic"),
          pybind11::arg("msg_type_name"),
          pybind11::arg("options"))
      .def("advertised_topics", &Node::AdvertisedTopics)
      .def("subscribe", [](
          Node &_node,
          std::string &_topic,
          std::function<void(const google::protobuf::Message &_msg)> &_callback,
          std::string &_msg_type_name,
          const SubscribeOptions &_opts)
          {
            return _node.Subscribe(_topic, _callback, _opts);
          },
          pybind11::arg("topic"),
          pybind11::arg("callback"),
          pybind11::arg("msg_type_name"),
          pybind11::arg("options"))
      .def("subscribed_topics", &Node::SubscribedTopics)
      ;

  py::class_<ignition::transport::Node::Publisher>(module, "Publisher")
      .def(py::init<>())
      .def("valid", &ignition::transport::Node::Publisher::Valid)
      .def("publish", &ignition::transport::Node::Publisher::Publish,
          pybind11::arg("msg"))
      .def("throttled_update_ready",
          &ignition::transport::Node::Publisher::ThrottledUpdateReady)
      .def("has_connections",
          &ignition::transport::Node::Publisher::HasConnections);
      ;
}

/// \brief Define the ignition_transport module
PYBIND11_MODULE(ignition_transport, m) {
  pybind11_protobuf::ImportNativeProtoCasters();

  define_transport_node(m);
}
