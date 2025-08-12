#include "xuci/log.hpp"
#include "xuci/orchestrator.hpp"
#include <iostream>

#include <xuci/core.hpp>

using namespace xuci;

int main(int argc, char **argv) {
  log_fatal(argc < 2, "Provide a flag");

  Args args(argv + 1, argv + argc);
  
  Orchestrator orchestrator(args);

  orchestrator.process_args();

  return 0;
}
