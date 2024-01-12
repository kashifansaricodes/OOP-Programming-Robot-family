#pragma once

#include "mobile_robot.h"

namespace RWA2 {

    /**
     * @brief A class representing a wheeled robot that inherits from MobileRobot
     */
    class WheeledRobot : public MobileRobot {
    private:
    // ==================== attributes ====================
        double wheel_diameter_; /**< The diameter of the robot's wheels */
        int number_of_wheels_{2}; /**< The number of wheels on the robot */
        double desired_speed_; /**< The desired speed of the robot */

    // ==================== methods ====================
        /**
         * @brief Accelerate the robot by the given amount
         *
         * @param amount The amount to accelerate the robot by
         */
        void accelerate(double amount);

        /**
         * @brief Decelerate the robot by the given amount
         *
         * @param amount The amount to decelerate the robot by
         */
        void decelerate(double amount);

        /**
         * @brief Brake the robot
         *
         */
        void brake();

    public:
    // ==================== constructors ====================
        /**
         * @brief Constructor for the WheeledRobot class.
         *
         * @param robot_model The model of the wheeled robot.
         * @param x The x-coordinate of the wheeled robot's position.
         * @param y The y-coordinate of the wheeled robot's position.
         * @param theta The orientation of the wheeled robot.
         * @param wheel_diameter The diameter of the wheeled robot's wheels.
         * @param number_of_wheels The number of wheels on the wheeled robot.
         * @param desired_speed The desired speed of the wheeled robot.
         */
        WheeledRobot(const std::string robot_model, double x, double y, double theta, double wheel_diameter,
                     int number_of_wheels, double desired_speed)
            : RWA2::MobileRobot(x, y, theta, 100, robot_model, "Li-ion", false), wheel_diameter_(wheel_diameter),
              number_of_wheels_(number_of_wheels), desired_speed_(desired_speed) {}
    
        /**
         * @brief Constructor for the WheeledRobot class.
         *
         * @param robot_model The model of the wheeled robot.
         * @param x The x-coordinate of the wheeled robot's position.
         * @param y The y-coordinate of the wheeled robot's position.
         * @param theta The orientation of the wheeled robot.
         * @param wheel_diameter The diameter of the wheeled robot's wheels.
         * @param number_of_wheels The number of wheels on the wheeled robot.
         * @param desired_speed The desired speed of the wheeled robot.
         * @param battery_charge The battery capacity of the wheeled robot.
         * @param battery_model The battery type of the wheeled robot.
         * @param is_charging Whether the wheeled robot is plugged in or not. 
         */
        WheeledRobot(const std::string robot_model, double x, double y, double theta, double wheel_diameter,
                     int number_of_wheels, double desired_speed, int battery_charge, std::string battery_model,
                     bool is_charging)
            : RWA2::MobileRobot(x, y, theta, battery_charge, robot_model, battery_model, is_charging),
              wheel_diameter_(wheel_diameter), number_of_wheels_(number_of_wheels), desired_speed_(desired_speed) {}


    // ==================== methods ====================
        /**
         * @brief Move the robot
         *
         * @param distance The distance to move the robot
         * @param angle The angle to move the robot
         */
        void move(double distance, double angle) override;

        /**
         * @brief Print the status of the robot
         *
         */
        void print_status() override;

    // ==================== accessors ====================
        /**
         * @brief Get the number of wheels on the robot
         *
         * @return int The number of wheels on the robot
         */
        int get_number_of_wheels() const { return number_of_wheels_; }

        /**
         * @brief Get the diameter of the robot's wheels
         *
         * @return double The diameter of the robot's wheels
         */
        double get_wheel_diameter() const { return wheel_diameter_; }

        /**
         * @brief Get the desired speed of the robot
         *
         * @return double The desired speed of the robot
         */
        double get_desired_speed() const { return desired_speed_; }

    // ==================== mutators ====================

        /**
         * @brief Set the number of wheels on the robot
         *
         * @param number_of_wheels The number of wheels on the robot
         */
        void set_number_of_wheels(int number_of_wheels) { number_of_wheels_ = number_of_wheels; }

        /**
         * @brief Set the diameter of the robot's wheels
         *
         * @param wheel_diameter The diameter of the robot's wheels
         */
        void set_wheel_diameter(double wheel_diameter) { wheel_diameter_ = wheel_diameter; }

        /**
         * @brief Set the desired speed of the robot
         *
         * @param desired_speed The desired speed of the robot
         */
        void set_desired_speed(double desired_speed) { desired_speed_ = desired_speed; }

    protected:
    // ==================== methods ====================
        /**
         * @brief Rotate the robot
         *
         * @param angle The angle to rotate the robot
         */
        void rotate(double angle) override;
    };

}; // namespace RWA2
