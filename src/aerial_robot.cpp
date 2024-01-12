// AerialRobot.cpp
#include "aerial_robot.h"
#include <iostream>
#include <thread>

namespace RWA2 {

    void AerialRobot::take_off(double altitude) {
        if (is_flying()) {
            std::cout << "Robot is already flying.\n";
            return;
        }
        else{
        double speed = has_wings_ ? 3.0 : 1.5;
        double time = altitude / speed;
        std::cout << "Robot is taking off to reach altitude of " << altitude << " m.\n";
        std::this_thread::sleep_for(std::chrono::duration<double>(time));
        std::cout << "Robot has reached altitude of " << altitude << " m.\n";
        set_altitude(altitude);
        set_flying(true);
        }
    }

    void AerialRobot::land() {
        if (!is_flying()) {
            std::cout << "Robot is not flying.\n";
            return;
        }
        else {
            double speed = has_wings_ ? 4.0 : 2.0;
            double time = get_altitude() / speed;
            std::cout << "Robot is landing at a speed of " << speed << " m/s.\n";
            std::this_thread::sleep_for(std::chrono::duration<double>(time));
            std::cout << "Robot has landed.\n";
            set_altitude(0);
            set_flying(false);
        }
    }

    void AerialRobot::rotate(double angle) {
        MobileRobot::rotate(angle);
        std::cout << "AerialRobot::" << MobileRobot::get_model() << " rotated " << angle << " degrees.\n";
        // Implementation of rotate method
    }

    void AerialRobot::print_status() {
        // Implementation of print_status method
        std::cout << "Robot Class: AerialRobot" << '\n';
        MobileRobot::print_status();
        std::cout << "Has wings: " << has_wings_ << '\n';
        std::cout << "Is flying: " << is_flying_ << '\n';
        std::cout << "Altitude: " << altitude_ << " m\n";

    }

    
    void AerialRobot::move(double distance, double angle) {
        if (distance <= 50) {
            double battery_consumption = distance * 2;
            if (battery_.get_current_charge() < battery_consumption) {
                std::cout << "Battery charge is not enough to move.\n";
                std::cout << "Starting to charge the battery...\n";
                battery_.start_charging();
            }
            get_sensor_reading(5);
            take_off(distance/2);
            rotate(angle);
            land();
            std::cout << MobileRobot::get_model() << " reached an altitude of " << distance/2 << " meters and then landed.\n";
            print_status();
            battery_.discharge(battery_consumption);
        }
        else {
            std::cout << "Error: Altitude is too high, battery not enough, Altitude should be less than 25m.\n";
        }
    }
} ;// namespace RWA2
