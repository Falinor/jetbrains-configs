#include <iostream>

#include "engine.hh"

Engine::Engine(int fuel)
  : fuel_(fuel)
{}

bool Engine::start()
{
  if (fuel_ <= 0)
    return false;
  std::cout << "Engine started with " << fuel_ << " fuel units" << std::endl;
  --fuel_;
  return true;
}

void Engine::use(int consumed)
{
  if (fuel_ - consumed >= 0)
  {
    std::cout << "Engine uses " << consumed << " fuel units" << std::endl;
    fuel_ -= consumed;
  }
  else
    fuel_ -= fuel_;
}

void Engine::stop() const
{
  std::cout << "Stop Engine" << std::endl;
}

void Engine::fill(int fuel)
{
  std::cout << "Filled with " << fuel << " fuel units" << std::endl;
}

int main()
{
  Engine engine(42);
  engine.use(10);
  engine.fill(10);
  engine.use(10);
  engine.stop();
}
