
#include "battery.h"
#include <chrono>
#include <thread>

void RWA2::Battery::start_charging() {

    if(is_charging() == false){
      set_is_charging(true);
      std::cout << "Sensor " << RWA2::Battery::get_model() << " is charging"<< '\n';
      double remaining_charge{static_cast<double>(100) - static_cast<double>(RWA2::Battery::get_current_charge())};
      double charging_time{0.0};
      if (RWA2::Battery::get_model()=="Li-ion"){charging_time = remaining_charge/2;}
      else if (RWA2::Battery::get_model()=="LiFePO4"){charging_time = remaining_charge/4;}
      std::cout << "Battery will take " << charging_time << " seconds to charge" << '\n';
      std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(charging_time)));
      set_current_charge(100);
      stop_charging();
    }
    else{
      std::cout << "Sensor " << RWA2::Battery::get_model() << " is already charging" << '\n';
    }
}


void RWA2::Battery::stop_charging() {
  set_is_charging(false);
  std::cout << "Sensor " << RWA2::Battery::get_model() << " is fully charged"<< '\n';
}

void RWA2::Battery::discharge(double amount) {
  set_current_charge(static_cast<int>(get_current_charge() - amount));
  std::cout << "Current charge: " << get_current_charge() << '\n';
}