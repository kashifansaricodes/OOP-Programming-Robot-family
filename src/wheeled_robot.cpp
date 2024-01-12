// WheeledRobot.cpp
#include "wheeled_robot.h"
#include <iostream>
#include <thread>

namespace RWA2 {

   
    void WheeledRobot::accelerate(double amount) {
        while (MobileRobot::get_speed() <= get_desired_speed()) {
            MobileRobot::set_speed(MobileRobot::get_speed() + amount);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << MobileRobot::get_model() << " has reached the desired speed of " << get_desired_speed() << " m/s\n";
    }

    void WheeledRobot::decelerate(double amount) {
        while (MobileRobot::get_speed() >= 0) {
            MobileRobot::set_speed(MobileRobot::get_speed() - amount);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        if (MobileRobot::get_speed() < 0) {
        MobileRobot::set_speed(0);
        }
        std::cout << MobileRobot::get_model() << " has come to a complete stop.\n";
    }

    void WheeledRobot::brake() {
        // Implementation of brake method
        MobileRobot::set_speed(0);
    }

    void WheeledRobot::rotate(double angle) {
        MobileRobot::rotate(angle);
        std::cout << "WheeledRobot::" << MobileRobot::get_model() << " rotated " << angle << " degrees.\n";
        // Implementation of rotate method
    }

    void WheeledRobot::print_status() {
        // Implementation of print_status method
        std::cout << "Robot Class: WheeledRobot" << '\n';
        MobileRobot::print_status();
        std::cout << "Wheel diameter: " << wheel_diameter_ << " m\n";
        std::cout << "Number of wheels: " << number_of_wheels_ << '\n';
        std::cout << "Desired speed: " << desired_speed_ << '\n';
    }

    void WheeledRobot::move(double distance, double angle) {
        if(distance<=100)
        {
        double battery_consumption = distance * 1;
            if (battery_.get_current_charge() < battery_consumption) {
                std::cout << "Battery charge is not enough to move.\n";
                std::cout << "Starting to charge the battery...\n";
                battery_.start_charging();
                }
            get_sensor_reading(5);
            rotate(angle);
            accelerate(2);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>((distance - 2) * 1000)));
            decelerate(2);
            brake();
            std::cout << MobileRobot::get_model() << " drove " << distance << " m.\n";
            print_status();
            battery_.discharge(battery_consumption);
        }
        else
        {
            std::cout<<"Distance is greater than 100m, so robot cannot move\n";
        }
    }
}; // namespace RWA2
