// aquatic_robot.h
#pragma once

#include "mobile_robot.h"

/**
 * @brief Namespace for the RWA2 project
 *
 */
namespace RWA2 {
    /**
     * @brief Class for the aquatic robot
     *
     */
    class AquaticRobot : public MobileRobot {

    private:
        // ==================== attributes ====================
        bool has_fins_;
        double depth_{0.0};
        bool is_diving_{false};

        // ==================== methods ====================
        /**
         * @brief Dive to the given depth
         *
         * @param depth
         */
        void dive(double depth);
        /**
         * @brief Surface the robot
         *
         */
        void surface();
        /**
         * @brief Move the robot
         *
         * @param distance
         * @param angle
         */

    public:
        // ==================== constructors ====================

        /**
         * @brief Constructor for the AquaticRobot class.
         * 
         * @param robot_model The model of the aquatic robot.
         * @param hasFins Whether the aquatic robot has fins or not.
         * @param x The x-coordinate of the aquatic robot's position.
         * @param y The y-coordinate of the aquatic robot's position.
         * @param theta The orientation of the aquatic robot.
         */
        AquaticRobot(const std::string robot_model, bool hasFins, double x, double y, double theta)
            : RWA2::MobileRobot(x, y, theta, 100, robot_model, "Li-ion", false), has_fins_(hasFins) {}

        /**
         * @brief Constructor for the AquaticRobot class.
         * 
         * @param robot_model The model of the aquatic robot.
         * @param hasFins Whether the aquatic robot has fins or not.
         * @param x The x-coordinate of the aquatic robot's position.
         * @param y The y-coordinate of the aquatic robot's position.
         * @param theta The orientation of the aquatic robot.
         * @param battery_charge The current battery charge of the aquatic robot.
         * @param battery_model The model of the battery used by the aquatic robot.
         * @param is_charging Whether the aquatic robot is currently charging or not.
         */
        AquaticRobot(const std::string robot_model, bool hasFins, double x, double y, double theta, int battery_charge, std::string battery_model, bool is_charging)
            : RWA2::MobileRobot(x, y, theta, battery_charge, robot_model, battery_model, is_charging), has_fins_(hasFins) {}


        // ==================== accessors ====================
        /**
         * @brief Get the depth of the robot
         *
         * @return double
         */
        double get_depth() const { return depth_; }

        /**
         * @brief Get the status of the robot
         *
         * @return true if the robot is diving
         * @return false if the robot is not diving
         */
        bool is_diving() const { return is_diving_; }

        /**
         * @brief Get the status of the robot
         *
         * @return true if the robot has fins
         * @return false if the robot does not have fins
         */
        bool has_fins() const { return has_fins_; }

        // ==================== mutators ====================
        /**
         * @brief Set the depth of the robot
         *
         * @param depth
         */
        void set_depth(double depth) { depth_ = depth; }

        /**
         * @brief Set the status of the robot
         *
         * @param diving
         */
        void set_diving(bool diving) { is_diving_ = diving; }

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
