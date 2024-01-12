// aerial_robot.h
#pragma once

#include "mobile_robot.h"

namespace RWA2 {

    class AerialRobot : public MobileRobot {
    private:
    // ==================== attributes ====================
        bool has_wings_;
        double altitude_{0.0};
        bool is_flying_{false};

    // ==================== methods ====================
        /**
         * @brief Take off to the given altitude
         *
         * @param altitude
         */
        void take_off(double altitude);
        /**
         * @brief Land the robot
         *
         */
        void land();

    public:
    // ==================== constructors ====================
        /**
         * @brief Constructor for the AerialRobot class.
         *
         * @param robot_model The model of the aerial robot.
         * @param hasWings Whether the aerial robot has wings or not.
         * @param x The x-coordinate of the aerial robot's position.
         * @param y The y-coordinate of the aerial robot's position.
         * @param theta The orientation of the aerial robot.
         */
        AerialRobot(const std::string robot_model, bool hasWings, double x, double y, double theta)
            : RWA2::MobileRobot(x, y, theta, 100, robot_model, "Li-ion", false), has_wings_(hasWings) {}

        /**
         * @brief Constructor for the AerialRobot class.
         *
         * @param robot_model The model of the aerial robot.
         * @param hasWings Whether the aerial robot has wings or not.
         * @param x The x-coordinate of the aerial robot's position.
         * @param y The y-coordinate of the aerial robot's position.
         * @param theta The orientation of the aerial robot.
         * @param battery_charge The battery capacity of the aerial robot.
         * @param battery_model The battery type of the aerial robot.
         * @param is_charging Whether the aerial robot is plugged in or not.
         */
        AerialRobot(const std::string robot_model, bool hasWings, double x, double y, double theta,
                    int battery_charge, std::string battery_model, bool is_charging)
            : RWA2::MobileRobot(x, y, theta, battery_charge, robot_model, battery_model, is_charging),
              has_wings_(hasWings) {}

    //

    // ==================== methods ====================
        /**
         * @brief Move the robot
         *
         * @param distance
         * @param angle
         */
        
        void move(double distance, double angle) override;
        


        /**
         * @brief Print the status of the robot
         *
         */
        void print_status() override;

    // ==================== accessors ====================
        /**
         * @brief Get the altitude of the robot
         *
         * @return double
         */
        double get_altitude() const { return altitude_; }

        /**
         * @brief Get the status of the robot
         *
         * @return true if the robot is flying
         * @return false if the robot is not flying
         */
        bool is_flying() const { return is_flying_; }

        /**
         * @brief Get the status of the robot
         *
         * @return true if the robot has wings
         * @return false if the robot does not have wings
         */
        bool has_wings() const { return has_wings_; }

    // ==================== mutators ====================
        /**
         * @brief Set the altitude of the robot
         *
         * @param altitude
         */
        void set_altitude(double altitude) { altitude_ = altitude; }

        /**
         * @brief Set the status of the robot
         *
         * @param flying
         */
        void set_flying(bool flying) { is_flying_ = flying; }

    protected:
    // ==================== methods ====================
            /**
         * @brief Rotate the robot
         *
         * @param angle
         */
        void rotate(double angle) override;
    };

} ;// namespace RWA2
