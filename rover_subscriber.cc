#include <iostream>
#include <string>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>

void twist_cb(const ignition::msgs::Twist &_msg)
{
  std::cout << _msg.DebugString();
}

int main(int argc, char **argv)
{
  ignition::transport::Node node;
  std::string topic = "/twist";

  // Subscribe to a topic by registering a callback.
  if (!node.Subscribe(topic, twist_cb))
  {
    std::cerr << "Error subscribing to topic [" << topic << "]" << std::endl;
    return -1;
  }

  // spin.
  ignition::transport::waitForShutdown();
  return 0;
}