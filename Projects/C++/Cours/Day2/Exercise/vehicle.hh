#ifndef VEHICLE_HH_
# define VEHICLE_HH_

# include <string>

class Vehicle
{
public:
  Vehicle(std::string model);
  virtual bool start() = 0;
  virtual void stop() const = 0;

private:
  std::string model_;
};

#endif /* !VEHICLE_HH_ */
