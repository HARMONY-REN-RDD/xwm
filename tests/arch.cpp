#include "xwm/orchestrator.hpp"
#include <xwm/base_architecture.hpp>

#include <iostream>

class test : public xwm::BaseArchitecture {

public:
  void fetch() { std::cout << "fetch" << std::endl; }
  void decode() { std::cout << "decode" << std::endl; }
  void execute() {
    std::cout << "execute" << std::endl;
    for (auto arg: this->_args) {
      std::cout << arg << std::endl;
    }
    stop_execution();
  }

  void run() { std::cout << "run" << std::endl; }
};

XWM_EXPORT xwm::BaseArchitecture *load_architecture(xwm::Orchestrator *) { return new test(); }
