#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the RWA2 project
 *
 */
namespace RWA2{
/**
 * @brief Class for the battery
 *
 */
class Battery {
 private:
  // ==================== attributes ====================
  std::string model_;
  int current_charge_;
  bool is_charging_;
  // ==================== methods ====================
  /**
   * @brief Stop charging the battery
   *
   */
  void stop_charging();

 public:
  // ==================== constructors ==================== 

  /**
   * @brief Constructor for the Battery class.
   * 
   * @param model The model of the battery.
   * @param current_charge The current charge level of the battery.
   * @param is_charging Whether or not the battery is currently charging.
   */
  Battery(std::string model, int current_charge, bool is_charging)
      : model_{model}, current_charge_{current_charge}, is_charging_{is_charging} {} 

  // ==================== accessors ====================
  /**
   * @brief Get the capacity of the battery
   *
   * @return double
   */
  int get_current_charge() const { return current_charge_; }

  /**
   * @brief Get the model of the battery
   *
   * @return std::string
   */
  std::string get_model() const { return model_; }

  /**
   * @brief Get the status of the battery
   *
   * @return true if the battery is charging
   * @return false if the battery is not charging
   */ 
  bool is_charging() const { return is_charging_; }

  // ==================== mutators ====================
  /**
   * @brief Set the capacity of the battery
   *
   * @param capacity
   */
  void set_current_charge(int current_charge) { current_charge_ = current_charge; }

  /**
   * @brief Set the status of the battery
   *
   * @param is_charging
   */
  void set_is_charging(bool is_charging) { is_charging_ = is_charging; }

  // ==================== methods ====================
  /**
   * @brief Start charging the battery
   *
   */
  void start_charging();

  /**
   * @brief Discharge the battery
   *
   * @param amount Amount of charge to discharge
   */
  void discharge(double amount);

};  // class Battery
}  // namespace RWA2
