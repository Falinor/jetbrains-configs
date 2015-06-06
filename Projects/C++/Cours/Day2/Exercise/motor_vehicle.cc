#include <iostream>

#include "motor_vehicle.hh"

MotorVehicle::MotorVehicle(std::string model, int fuel)
  : Vehicle(model)
  , engine_(Engine engine(fuel))
{}

bool MotorVehicle::start()
{
  
}

void MotorVehicle::stop() const
{

}

void MotorVehicle::cruise(int fuel)
{

}

void MotorVehicle::fill(int fuel)
{

}
