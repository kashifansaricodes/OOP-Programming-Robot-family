#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "battery.h"
#include "sensor.h"

/**
 * @brief 
 * 
 */
namespace RWA2 {

/**
 * @brief Class for the mobile robot.
 *
 */
class MobileRobot {
 protected:
  // ==================== attributes ====================
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_{0.0};
  //<! model of the robot
  std::string model_;
  //<! battery of the robot
  RWA2::Battery battery_;
  //<! sensors of the robot
  std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;


  // ==================== methods ====================
  /**
   * @brief Rotate the robot by a given angle.
   *
   * @param angle Angle to rotate (in degrees).
   */
  virtual void rotate(double angle);

 public:
  // ==================== constructors ====================
  /**
   * @brief Construct a new Mobile Robot object.
   * 
   * @param x The x-coordinate of the robot's position.
   * @param y The y-coordinate of the robot's position.
   * @param orientation The orientation of the robot in radians.
   * @param battery_charge The initial charge of the robot's battery, defaults to 100.0.
   * @param robot_model The model of the robot, defaults to "Robot".
   * @param battery_model The model of the robot's battery, defaults to "Li-ion".
   * @param is_charging Whether the robot's battery is currently charging, defaults to false.
   */
  MobileRobot(double x, double y, double orientation, int battery_charge = 100, std::string robot_model = "Robot" , std::string battery_model = "Li-ion", bool is_charging = false)
      : position_{x, y},
        orientation_{orientation},
        model_{robot_model},
        battery_(battery_model, battery_charge, is_charging) {}

  /**
   * @brief Construct a new Mobile Robot object with default values.
   */
  MobileRobot() : MobileRobot(0, 0, 0) {}

  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot.
   *
   * @return std::pair<double, double>
   */
  std::pair<double, double> get_position() const { return position_; }

  /**
   * @brief Get the orientation of the robot.
   *
   * @return double
   */
  double get_orientation() const { return orientation_; }

  /**
   * @brief Get the speed of the robot.
   *
   * @return double
   */
  double get_speed() const { return speed_; }

  /**
   * @brief Get the battery level of the robot.
   *
   * @return double
   */
  double get_battery_level() const { return battery_.get_current_charge(); }

  /**
    * @brief Get the model of the robot.
    *
    * @return std::string
    */
  std::string get_model() const { return model_; }

  // ==================== mutators ====================
  /**
   * @brief Set the position of the robot.
   *
   * @param x x position.
   * @param y y position.
   */
  void set_position(double x, double y) {
    position_.first = x;
    position_.second = y;
  }

  /**
   * @brief Set the orientation of the robot.
   *
   * @param orientation Orientation of the robot (in degrees).
   */
  void set_orientation(double orientation) { orientation_ = orientation; }

  /**
   * @brief Set the speed of the robot.
   *
   * @param speed Speed of the robot (in m/s).
   */
  void set_speed(double speed) { speed_ = speed; }

  // ==================== methods ====================
  /**
   * @brief Move the robot forward by a given distance.
   *
   * @param distance Distance to move (in m).
   * @param angle Angle to move (in degrees).
   */
  virtual void move(double distance, double angle);

  /**
   * @brief Print the status of the robot.
   *
   * @param robot_name Name of the robot.
   */ 
  virtual void print_status();

  /**
   * @brief Add a sensor to the robot.
   *
   * @param sensor Sensor to add.
   */
  virtual void add_sensor(std::unique_ptr<RWA2::Sensor> sensor);

  /**
   * @brief Get the sensor reading.
   *
   * @param period Period of the sensor reading.
   */
  void get_sensor_reading(unsigned int period) const;

  // ==================== friend functions ====================
  /**
   * @brief Operator overloading for the << operator.
   *
   * @param os Output stream.
   * @param robot Robot to print.
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& os, const MobileRobot& robot);

};  // class MobileRobot

}  // namespace RWA2
