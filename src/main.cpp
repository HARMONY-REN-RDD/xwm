#include <iostream>

#include <xuci/core.hpp>

int main() {

  xuci::Register<2> x;

  std::cout << x.to_hex() << std::endl;

  return 0;
}