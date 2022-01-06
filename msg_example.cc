#include <iostream>

#include <ignition/msgs.hh>

using namespace ignition;

int main(int argc, const char *argv[])
{
  std::cout << "@ign_examples//:msg_example" << std::endl;

  // https://ignitionrobotics.org/api/msgs/8.1/cppgetstarted.html
  {
    ignition::msgs::Vector3d point1;
    point1.set_x(1);
    point1.set_y(3);
    point1.set_z(5);
    ignition::msgs::Vector3d point2;
    point2.set_x(2);
    point2.set_y(4);
    point2.set_z(6);
    std::cout << "Point1:\n" << point1.DebugString() << std::endl;
    std::cout << "Point2:\n" << point2.DebugString() << std::endl;
  }

  return 0;
}
