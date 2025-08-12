#pragma once

#include <string>
#include <vector>

#include <xuci/base_architecture.hpp>



namespace xuci {

using Args = std::vector<std::string>;

class Orchestrator {
private:
  BaseArchitecture *architecture = nullptr;

  Args *args = nullptr;

  // Architecture shared lib loading
  void *handle = nullptr;

public:
  Orchestrator(Args &args);
  ~Orchestrator();

  void process_args();

  BaseArchitecture *load_architecture(std::string path);
};

} // namespace xuci
