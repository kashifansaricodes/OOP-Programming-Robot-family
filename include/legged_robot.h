// leggedrobot.h
#pragma once

#include "mobile_robot.h"

namespace RWA2 {
    /**
     * @brief The LeggedRobot class represents a legged robot that can move, rotate, jump, and kick.
     */
    class LeggedRobot : public MobileRobot {
    private:
    // ==================== attributes ====================
        double height_; /**< The height of the legged robot. */
        int leg_strength_; /**< The strength of the legged robot. */
        int number_of_legs_{2}; /**< The number of legs of the legged robot. */

    // ==================== methods ====================
        /**
         * @brief Kick the ball
         *
         */
        void kick();
        /**
         * @brief Jump the robot by the given amount
         *
         * @param amount The amount to jump by
         */
        void jump(double amount);

    public:
    // ==================== constructors ====================

        /**
         * @brief Constructor for the LeggedRobot class.
         *
         * @param robot_model The model of the legged robot.
         * @param height The height of the legged robot.
         * @param leg_strength The strength of the legged robot.
         * @param x The x-coordinate of the legged robot's position.
         * @param y The y-coordinate of the legged robot's position.
         * @param theta The orientation of the legged robot.
         */
        LeggedRobot(const std::string robot_model, double height, int leg_strength, double x, double y, double theta)
            : RWA2::MobileRobot(x, y, theta, 100, robot_model, "Li-ion", false), height_(height), leg_strength_(leg_strength) {}

        
        /**
         * @brief Constructor for the LeggedRobot class.
         *
         * @param robot_model The model of the legged robot.
         * @param height The height of the legged robot.
         * @param leg_strength The strength of the legged robot.
         * @param number_of_legs The number of legs of the legged robot.
         * @param x The x-coordinate of the legged robot's position.
         * @param y The y-coordinate of the legged robot's position.
         * @param theta The orientation of the legged robot.
         * @param battery_charge The battery charge of the legged robot.
         * @param battery_model The battery model of the legged robot.
         * @param is_charging Whether the legged robot is charging or not.
         */
        LeggedRobot(const std::string robot_model, double height, int leg_strength, int number_of_legs, double x, double y, double theta,
                    int battery_charge, std::string battery_model, bool is_charging)
            : RWA2::MobileRobot(x, y, theta, battery_charge, robot_model, battery_model, is_charging),
              height_(height), leg_strength_(leg_strength), number_of_legs_(number_of_legs) {}


    // ==================== methods ====================

        /**
         * @brief Move the legged robot by the given distance and angle.
         *
         * @param distance The distance to move the legged robot.
         * @param angle The angle to move the legged robot.
         */
        void move(double distance, double angle) override;


        /**
         * @brief Print the status of the legged robot.
         *
         */
        void print_status() override;

    // ==================== accessors ====================

        /**
         * @brief Get the height of the legged robot.
         *
         * @return double
         */
        double get_height() const { return height_; }

        /**
         * @brief Get the strength of the legged robot.
         *
         * @return int
         */
        int get_leg_strength() const { return leg_strength_; }

        /**
         * @brief Get the number of legs of the legged robot.
         *
         * @return int
         */
        int get_number_of_legs() const { return number_of_legs_; }

    // ==================== mutators ====================

        /**
         * @brief Set the height of the legged robot.
         *
         * @param height
         */
        void set_height(double height) { height_ = height; }

        /**
         * @brief Set the strength of the legged robot.
         *
         * @param leg_strength
         */
        void set_leg_strength(int leg_strength) { leg_strength_ = leg_strength; }

        /**
         * @brief Set the number of legs of the legged robot.
         *
         * @param number_of_legs
         */
        void set_number_of_legs(int number_of_legs) { number_of_legs_ = number_of_legs; }    

    protected:
    // ==================== methods ====================
        /**
         * @brief Rotate the legged robot by the given angle.
         *
         * @param angle The angle to rotate the legged robot.
         */
        void rotate(double angle) override;
    };

} ;// namespace RWA2
