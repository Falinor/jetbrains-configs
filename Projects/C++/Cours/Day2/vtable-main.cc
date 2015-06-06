#include <iostream>
#include "VTableAccessor.hh"

// Method used show that class' methods has been replaced.
void methodRemover()
{
  std::cout << "\033[1;31mThis method has been replaced.\033[0;39m" << std::endl;
}

int main(void)
{
  VTableTested vt(42);
  VTableAccessor vAccess;
  VTableTested* pvt = &vt;
  VTableAccessor* pvAccess = &vAccess;

  std::cout << "Calling methods of VTableTested:" << std::endl;
  std::cout << "print_i():" << std::endl;
  pvt->print_i();

  std::cout << "print_2i():" << std::endl;
  pvt->print_2i();

  std::cout << std::endl;

  std::cout << "Accessing vtable methods via VTableAccessor:" << std::endl;
  std::cout << "print_i():" << std::endl;
  pvAccess->callMethod(pvt, 0);

  std::cout << "print_2i():" << std::endl;
  pvAccess->callMethod(pvt, 1);

  std::cout << "Choose a method to replace:" << std::endl;
  std::cout << "  0 - print_i()" << std::endl;
  std::cout << "  1 - print_2i()" << std::endl;
  int i = -1;

  std::cin >> i;

  if (i != 1 && i != 0)
  {
    std::cout << "I said 0 or 1!" << std::endl;
    return 0;
  }

  // Replacing the method at index 0 of the vtable (print_i)
  // with method methodRemover() (see above.)
  std::cout << "#########################################################" << std::endl;
  std::cout << "Replacing vtable methods at index " << i
	    << ((i == 0) ? " (print_i)" : " (print_2i)")
	    << ":" << std::endl;
  std::cout << "#########################################################" << std::endl;
  pvAccess->replaceMethod(pvt, i, &methodRemover);

  std::cout << std::endl;

  std::cout << "Calling method print_i:" << std::endl;
  std::cout << "print_i():" << std::endl;
  pvt->print_i();

  std::cout << "print_2i():" << std::endl;
  pvt->print_2i();

  std::cout << std::endl;
  std::cout << "Accessing new method via VTableAccessor:" << std::endl;
  std::cout << "print_i():" << std::endl;
  pvAccess->callMethod(pvt, 0);

  std::cout << "print_2i():" << std::endl;
  pvAccess->callMethod(pvt, 1);

  return 0;
}
