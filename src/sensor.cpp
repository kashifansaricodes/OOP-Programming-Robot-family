#include "sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

//==============================================================================
void RWA2::Sensor::read_data(unsigned int duration) {

    std::cout << "Sensor " << RWA2::Sensor::get_model() << " gathering data for " << duration << " seconds." << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    //generate random double between 1 and 100
    std::random_device rd;  // Random device engine, usually based on
                            // /dev/urandom on UNIX-like OSes
    std::mt19937 gen(rd());  // Initializes with the random device
    std::uniform_real_distribution<> dis(0.0, 30.0);
    for(int i=0; i<10; i++){
        data_[i] = dis(gen);
    }
    std::cout << "Sensor " << RWA2::Sensor::get_model() << " reading complete." << '\n';
}

