#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>
#include <array>

/**
 * @brief Namespace for the RWA2 project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the sensor
 *
 */
class Sensor {
 private:
  // ==================== attributes ====================
  std::string model_;
  std::array<double, 50> data_;


 public:
  // ==================== constructors ====================
  /**
   * @brief Construct a new Sensor object
   *
   * @param sensor_name
   */
  Sensor(std::string sensor_name) : model_{sensor_name} {}

  // ==================== accessors ====================
  /**
   * @brief Get the model of the sensor
   *
   * @return std::string
   */
  std::string get_model() const { return model_; }

  /**
   * @brief Get the sensor data
   *
   * @return std::array<double, 50>
   */
  std::array<double, 50> get_sensor_data() const { return data_; }

  // ==================== methods ====================
  /**
  * @brief Read the sensor data
  *
  * @param duration Duration of the reading (in s)
  */
  void read_data(unsigned int duration);

};  // class Sensor
}  // namespace RWA2
