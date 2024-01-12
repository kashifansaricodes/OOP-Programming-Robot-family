// AquaticRobot.cpp
#include "aquatic_robot.h"
#include <iostream>
#include <thread>

namespace RWA2 {

    void AquaticRobot::dive(double depth) {
        if (is_diving()) {
            std::cout << "Error: Robot is already diving.\n";
            return;
        }
        else
        {
        double speed = has_fins() ? 2.0 : 1.0;
        double time_to_reach_depth = depth / speed;
        std::cout << "Diving to a depth of " << depth << " meters...\n";
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time_to_reach_depth)));
        std::cout << "Reached a depth of " << depth << " meters.\n";
        set_depth(depth);
        set_diving(true);
        }
    }


    void AquaticRobot::surface() {
        if (!is_diving()) {
            std::cout << "Error: Robot is not diving.\n";
            return;
        }
        else{
        set_diving(false);
        double speed = has_fins() ? 4.0 : 2.0;
        double time_to_surface = get_depth() / speed;
        std::cout << "Ascending to the surface...\n";
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(time_to_surface)));
        std::cout << "Reached the surface.\n";
        set_depth(0.0);
        battery_.set_current_charge(100);//FIX Charge
        }
    }

    void AquaticRobot::rotate(double angle) {
        MobileRobot::rotate(angle);
        std::cout << "AquaticRobot::" << MobileRobot::get_model() << " rotated " << angle << " degrees.\n";
        // Implementation of rotate method
    }

    void AquaticRobot::print_status() {
        std::cout << "Robot Class: AquaticRobot" << '\n';
        MobileRobot::print_status();
        std::cout << "Has fins: " << has_fins() << '\n';
        std::cout << "Is diving: " << is_diving() << '\n';
        std::cout << "Depth: " << get_depth() << " m\n";
        // Implementation of print_status method
    }

    void AquaticRobot::move(double distance, double angle) {
    if (distance<=100){
    double battery_consumption = distance * 1;
    if (battery_.get_current_charge() < battery_consumption) {
        std::cout << "Battery charge is not enough to move.\n";
        std::cout << "Starting to charge the battery...\n";
        battery_.start_charging();
    }
    get_sensor_reading(5);
    rotate(angle);
    dive(distance/2);
    surface();
    std::cout << get_model() << " reached a depth of " << distance/2 << " meters and then surfaced.\n";
    print_status();
    battery_.discharge(battery_consumption);
    }
    else{
        std::cout << "Error: Depth is too much, battery not enough, Depth should be less than 50m.\n";
    }
}

}; // namespace RWA2
