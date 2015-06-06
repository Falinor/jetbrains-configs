#include <iostream>

#include "person.hh"

Person::Person(const std::string& name, const std::string& birthday)
  : name_(name)
{
  age_ = birthday;
}

Person::Person(const std::string& name, unsigned int age)
  : name_(name)
  , age_(age)
{}

int main()
{

}
