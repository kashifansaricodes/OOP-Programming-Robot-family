// LeggedRobot.cpp
#include "legged_robot.h"
#include <iostream>
#include <thread>

namespace RWA2 {

    void LeggedRobot::kick() {
        std::cout << MobileRobot::get_model() << " kicks with a strength of " << get_leg_strength() << '\n';
    }

    void LeggedRobot::jump(double amount) {
        //double jump_height = amount * leg_strength_ * 100; // convert amount to cm
        set_height((amount*0.01) * get_leg_strength()); 
        std::cout << MobileRobot::get_model() << " jumps at a height of " << get_height()*100<< " cm above the ground\n";
    }


    void LeggedRobot::rotate(double angle) {
        MobileRobot::rotate(angle);
        std::cout << "LeggedRobot::" << MobileRobot::get_model() << " rotated " << angle << " degrees.\n";
        // Implementation of rotate method
    }

    void LeggedRobot::print_status() {
        // Implementation of print_status method
        std::cout << "Robot Class: LeggedRobot" << '\n';
        MobileRobot::print_status();
        std::cout << "Height: " << height_ << " m\n";
        std::cout << "Leg strength: " << leg_strength_ << '\n';
        std::cout << "Number of legs: " << number_of_legs_ << '\n';
    }


    void LeggedRobot::move(double distance, double angle) {
        if(distance<=10)
        {
        double jump_height = (distance*100) * get_leg_strength();
        double jump_consumption = jump_height * 1;
        double kick_consumption = get_leg_strength() * 1;
        double total_consumption{jump_consumption + kick_consumption};


        if (battery_.get_current_charge() < total_consumption) {
            std::cout << "Battery charge is not enough to move.\n";
            std::cout << "Starting to charge the battery...\n";
            battery_.start_charging();
        }

        get_sensor_reading(5);
        rotate(angle);
        jump(distance);
        kick();
        print_status();
        battery_.discharge(total_consumption);

        }
        else
        {
            std::cout<<"Distance is greater than 10m, so robot cannot move\n";
        }
    }

}; // namespace RWA2
