#include "mobile_robot.h"
#include <chrono>
#include <iostream>
#include <thread>


//operator overloading for print_status()
// std::ostream& RWA2::operator<<(std::ostream& os, const RWA2::MobileRobot& robot) {
//   os << "Position: (" << robot.position_.first << "," << robot.position_.second
//      << ")"
//      << "\nOrientation: " << robot.orientation_
//      << "\nSpeed: " << robot.speed_ << " m/s" ;
//   return os;
// }
//==============================================================================

//add_sensor
void RWA2::MobileRobot::add_sensor(std::unique_ptr<RWA2::Sensor> sensor) {
  sensors_.push_back(sensor);
}

void RWA2::MobileRobot::get_sensor_reading(unsigned int period) const{

  for (const auto& sensor : sensors_) {
    sensor->read_data(period);
  }
  std::cout << "Sensor reading... " << '\n';
}


void RWA2::MobileRobot::rotate(double angle) {
  set_orientation(get_orientation() + angle);
  // std::cout << "Rotating " << angle << " degrees\n";
  // std::cout << "New orientation: " << get_orientation() << " degrees\n";
}

// void RWA2::MobileRobot::print_status() {
//   std::cout << *this << '\n';
// }

void RWA2::MobileRobot::print_status(){
  std::cout << "Robot name: " << get_model() << '\n';
  std::cout << "Robot position: (" << get_position().first << "," << get_position().second << ")" << '\n';
  std::cout << "Robot orientation: " << get_orientation() << '\n';
  std::cout << "Robot speed: " << get_speed() << '\n';
}


