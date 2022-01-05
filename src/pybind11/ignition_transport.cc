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

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include "pybind11_protobuf/native_proto_caster.h"

#include <google/protobuf/message.h>

#include <functional>

namespace py = pybind11;

// Needed internally to map the Python subscribe call to Node::SubscribeRaw
class MessageInfo
{
public:
  virtual ~MessageInfo() {}
  MessageInfo() {}

  public: const std::string &Topic() const;
  public: void SetType(const std::string &_type);
  public: const std::string &Type() const;
  public: void SetTopic(const std::string &_topic);
  public: const std::string &Partition() const;
  public: void SetPartition(const std::string &_partition);
};

const std::string kGenericMessageType = "google.protobuf.Message";

using RawCallback =
    std::function<void(const char *_msgData, const size_t _size,
        const MessageInfo &_info)>;

/// \brief A mock-up of ignition::transport::AdvertiseMessageOptions
class AdvertiseMessageOptions
{
public:
  virtual ~AdvertiseMessageOptions() {}
  AdvertiseMessageOptions() {}
  bool Throttled() const { return this->msgsPerSec != 0; }
  uint64_t MsgsPerSec() const { return this->msgsPerSec; }
  void SetMsgsPerSec(const uint64_t _newMsgsPerSec)
  {
    this->msgsPerSec = _newMsgsPerSec;
  }

  private:
    uint64_t msgsPerSec = 0;
};

class SubscribeOptions
{
public:
  virtual ~SubscribeOptions() {}
  SubscribeOptions() {}
  bool Throttled() const { return this->msgsPerSec != 0; }
  uint64_t MsgsPerSec() const { return this->msgsPerSec; }
  void SetMsgsPerSec(const uint64_t _newMsgsPerSec)
  {
    this->msgsPerSec = _newMsgsPerSec;
  }

  private:
    uint64_t msgsPerSec = 0;
};

/// \brief A mock-up of ignition::transport::Node
class Node
{
public:
  virtual ~Node() {}
  Node() {}

  class Publisher
  {
  public:
    virtual ~Publisher() {}
    Publisher() {}

    bool Valid() const { return true; }

    bool Publish(const google::protobuf::Message &_msg)
    {
      std::cout << _msg.GetTypeName() << "\n";
      std::cout << _msg.DebugString();
      return true;
    }

    bool ThrottledUpdateReady() const { return true; }

    bool UpdateThrottling() { return true; }

    bool HasConnections() const { return true; }
  };

  /// \brief A mock-up of the advertise function
  ///
  /// \param _msgTypeName is the protobuf type obtained using
  /// GetTypeName in C++ or DESCRIPTOR.full_name in Python
  Node::Publisher Advertise(
      const std::string &_topic,
      const std::string &_msgTypeName,
      const AdvertiseMessageOptions &_options = AdvertiseMessageOptions())
  {
    std::cout << "Advertising" << "\n"
        << "topic: " << _topic << "\n"   
        << "type: " << _msgTypeName << "\n";
    
    return Publisher();
  }

  std::vector<std::string> AdvertisedTopics() const
  {
    std::vector<std::string> topics;
    topics.push_back("/topic1");
    topics.push_back("/topic2");
    topics.push_back("/topic3");
    topics.push_back("/topic4");
    return topics;
  }

  bool Subscribe(
      const std::string &_topic,
      std::function<void(const google::protobuf::Message &_msg)> &_callback,
      const SubscribeOptions &_opts = SubscribeOptions())
  {
    // std::string msgType = kGenericMessageType;
    
    // RawCallback cb = [&](
    //   const char *_msgData,
    //   const size_t _size,
    //   const MessageInfo &_info) -> void
    // {
    //   // determine the correct message type
    //   msgType = _info.Type();

    //   // create the message from the string and metadata
    //   google::protobuf::Message msg;

    //   // call out callback
    //   _callback(msg);
    // };

    // return SubscribeRaw(_topic, cb, msgType, _opts);

    // Alternative
    // return Subscribe<google::protobuf::Message>(_topic, _callback, _opts);
    return true;
  }

  bool SubscribeRaw(
    const std::string &_topic,
    const RawCallback &_callback,
    const std::string &_msgType = kGenericMessageType,
    const SubscribeOptions &_opts = SubscribeOptions())
  {
    // forward to ignition::transport::Node::SubscribeRaw
  }

  std::vector<std::string> SubscribedTopics() const
  {
    std::vector<std::string> topics;
    topics.push_back("/topic1");
    topics.push_back("/topic2");
    topics.push_back("/topic3");
    topics.push_back("/topic4");
    return topics;
  }

};

// callback function examples
//
// https://pybind11.readthedocs.io/en/stable/advanced/cast/functional.html
//
int func_arg(const std::function<int(int)> &f) {
  return f(10);
}

std::function<int(int)> func_ret(const std::function<int(int)> &f) {
  return [f](int i) {
    return f(i) + 1;
  };
}

py::cpp_function func_cpp() {
  return py::cpp_function([](int i) { return i+1; },
      py::arg("number"));
}

class PubSub
{
public:
  virtual ~PubSub() {}
  PubSub() {}

  void Publish(const google::protobuf::Message &_msg)
  {
    if (this->callback)
    {
      this->callback(_msg);
    }
  }

  void Subscribe(std::function<void(const google::protobuf::Message &_msg)> &_callback)
  {
    this->callback = _callback;
  }

  std::function<void(const google::protobuf::Message &_msg)> callback;
};

/// \brief Define pybind11 bindings for ignition::transport objects
void define_transport_node(py::object module)
{
  py::class_<AdvertiseMessageOptions>(module, "AdvertiseMessageOptions")
      .def(py::init<>())
      .def_property_readonly("throttled",
          &AdvertiseMessageOptions::Throttled)
      .def_property("msgs_per_sec",
          &AdvertiseMessageOptions::MsgsPerSec,
          &AdvertiseMessageOptions::SetMsgsPerSec)
      ;

  py::class_<SubscribeOptions>(module, "SubscribeOptions")
      .def(py::init<>())
      .def_property_readonly("throttled",
          &SubscribeOptions::Throttled)
      .def_property("msgs_per_sec",
          &SubscribeOptions::MsgsPerSec,
          &SubscribeOptions::SetMsgsPerSec)
      ;

  py::class_<Node>(module, "Node")
      .def(py::init<>())
      .def("advertise", &Node::Advertise,
          pybind11::arg("topic"),
          pybind11::arg("msg_type_name"),
          pybind11::arg("options"))
      .def("advertised_topics", &Node::AdvertisedTopics)
      .def("subscribe", &Node::Subscribe,
          pybind11::arg("topic"),
          pybind11::arg("callback"),
          pybind11::arg("options"))
      .def("subscribed_topics", &Node::SubscribedTopics)
      ;

  py::class_<Node::Publisher>(module, "Publisher")
      .def(py::init<>())
      .def("valid", &Node::Publisher::Valid)
      .def("publish", &Node::Publisher::Publish,
          pybind11::arg("msg"))
      .def("throttled_update_ready",
          &Node::Publisher::ThrottledUpdateReady)
      .def("update_throttling",
          &Node::Publisher::UpdateThrottling)
      .def("has_connections",
          &Node::Publisher::HasConnections);
      ;

  py::class_<PubSub>(module, "PubSub")
      .def(py::init<>())
      .def("publish", &PubSub::Publish,
          pybind11::arg("msg"))
      .def("subscribe", &PubSub::Subscribe,
          pybind11::arg("callback"))
      ;

}

/// \brief Define the ignition_transport module
PYBIND11_MODULE(ignition_transport, m) {
  pybind11_protobuf::ImportNativeProtoCasters();

  define_transport_node(m);

  m.def("func_arg", &func_arg);
  m.def("func_ret", &func_ret);
  m.def("func_cpp", &func_cpp);
}
