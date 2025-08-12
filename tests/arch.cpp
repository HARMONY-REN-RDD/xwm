#include <xuci/base_architecture.hpp>

#include <iostream>

class test : public xuci::BaseArchitecture {

public:
  void fetch() { std::cout << "fetch" << std::endl; }
  void decode() { std::cout << "decode" << std::endl; }
  void execute() { std::cout << "execute" << std::endl; }
};

XUCI_EXPORT xuci::BaseArchitecture *load_architecture() {
  return new test();
}
