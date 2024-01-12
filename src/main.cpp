#include <memory>
#include <iostream>
#include "mobile_robot.h"
#include "aquatic_robot.h"
#include "aerial_robot.h"
#include "wheeled_robot.h"
#include "legged_robot.h"
#include "sensor.h"
#include "battery.h"

void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots)
{
    //For all robots in vector
    for (const auto &robot : robots)
        //Move 8 meters and rotate 5 degrees
        robot->move(8.0, 5.0);
}

int main()
{
    // Create a vector of derived mobile robots
    std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

    // Instatiate two instances of each derived classes with different properties
    // Add sensors to each robot
    /*AquaticRobot(const std::string robot_model, bool hasFins, double x, double y, double theta, double battery_charge, std::string battery_model, bool is_charging)*/
    std::unique_ptr<RWA2::MobileRobot> aquatic_ptr1 =
        std::make_unique<RWA2::AquaticRobot>("HoloOcean", false, 4.5, 7.5, 0.0, 100, "LiFePO4", false);

    aquatic_ptr1->add_sensor(std::make_unique<RWA2::Sensor>("multiScan100"));


    std::unique_ptr<RWA2::MobileRobot> aquatic_ptr2 =
        std::make_unique<RWA2::AquaticRobot>("SoFi", true, 2.5, 9.5, 0.0, 100, "Li-ion", false);

    aquatic_ptr2->add_sensor(std::make_unique<RWA2::Sensor>("LD-MRS"));

    /*AerialRobot(const std::string robot_model, bool hasWings, double x, double y, double theta,
                    double battery_charge, std::string battery_model, bool is_charging)*/
    std::unique_ptr<RWA2::MobileRobot> aerial_ptr1 =
        std::make_unique<RWA2::AerialRobot>("Erle-Plane", true, 2.5, 5.5, 45.0, 85, "LiFePO4", false);
    aerial_ptr1->add_sensor(std::make_unique<RWA2::Sensor>("OS2"));

    std::unique_ptr<RWA2::MobileRobot> aerial_ptr2 =
        std::make_unique<RWA2::AerialRobot>("Crazyflie", false, 0.5, 1.5, 45.0, 59, "Li-ion", false);

    aerial_ptr2->add_sensor(std::make_unique<RWA2::Sensor>("OS1"));

    /*LeggedRobot(const std::string robot_model, double height, int leg_strength, int number_of_legs, double x, double y, double theta,
                    double battery_charge, std::string battery_model, bool is_charging)*/

    std::unique_ptr<RWA2::MobileRobot> legged_ptr1 =
        std::make_unique<RWA2::LeggedRobot>("Atlas", 0.0, 4, 2, 1.5, 0.5, 30.0, 90, "LiFePO4", false);


    legged_ptr1->add_sensor(std::make_unique<RWA2::Sensor>("LMS5xx"));

    
    std::unique_ptr<RWA2::MobileRobot> legged_ptr2 =
        std::make_unique<RWA2::LeggedRobot>("Spot", 0.0, 4, 4, 3.5, 6.5, 45.0, 60, "LiFePO4", false);

    legged_ptr2->add_sensor(std::make_unique<RWA2::Sensor>("OS0"));

    /*WheeledRobot(const std::string robot_model, double x, double y, double theta, double wheel_diameter,
                     int number_of_wheels, double desired_speed, double battery_charge, std::string battery_model,
                     bool is_charging)*/
    std::unique_ptr<RWA2::MobileRobot> wheeled_ptr1 =
        std::make_unique<RWA2::WheeledRobot>("Dagu",4.5, 7.5, 0.0, 0.125, 6, 0.0, 67, "Li-ion", false);

    wheeled_ptr1->add_sensor(std::make_unique<RWA2::Sensor>("OSDome"));


    std::unique_ptr<RWA2::MobileRobot> wheeled_ptr2 =
        std::make_unique<RWA2::WheeledRobot>("Turtlebot",3.5, 6.5, 0.0, 0.66, 2, 0.0, 87, "LiFePO4", false);

    wheeled_ptr2->add_sensor(std::make_unique<RWA2::Sensor>("OSDome"));

    // Push classes to vector
    mobile_robots.push_back(std::move(aquatic_ptr1));
    mobile_robots.push_back(std::move(aerial_ptr1));
    mobile_robots.push_back(std::move(legged_ptr1));
    mobile_robots.push_back(std::move(wheeled_ptr1));
    mobile_robots.push_back(std::move(aquatic_ptr2));
    mobile_robots.push_back(std::move(aerial_ptr2));
    mobile_robots.push_back(std::move(legged_ptr2));
    mobile_robots.push_back(std::move(wheeled_ptr2));

    //Call move_robot function on all instatiated robots
    move_robot(mobile_robots);
}