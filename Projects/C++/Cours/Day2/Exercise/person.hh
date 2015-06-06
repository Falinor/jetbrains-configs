#ifndef PERSON_HH_
# define PERSON_HH_

# include <string>

class Person
{
public:
  Person(const std::string& name, const std::string& birthday);
  Person(const std::string& name, unsigned int age);

private:
  const std::string name_;
  unsigned int age_;
};

#endif /* !PERSON_HH_ */
