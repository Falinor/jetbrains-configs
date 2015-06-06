#ifndef MOTOR_VEHICLE_HH_
# define MOTOR_VEHICLE_HH_

# include <string>

# include "engine.hh"
# include "vehicle.hh"

class MotorVehicle : public Vehicle
{
public:
  MotorVehicle(std::string model, int fuel);
  virtual bool start() override;
  virtual void stop() const override;
  void cruise(int fuel);
  void fill(int fuel);

private:
  Engine engine_;
};

#endif /* !MOTOR_VEHICLE_HH_ */
