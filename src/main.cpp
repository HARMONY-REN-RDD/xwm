#include "xwm/log.hpp"

#include <fstream>
#include <numeric>
#include <sstream>
#include <string>
#include <xwm/core.hpp>
#include <xwm/xasm/isa.hpp>

#include <yaml-cpp/yaml.h>

using namespace xwm;

#include <algorithm>
#include <filesystem>

bool string_starts_with(std::string str, std::string prefix) {
  return str.find(prefix) == 0;
}

bool string_ends_with(std::string str, std::string suffix) {
  return str.find(suffix) == str.length() - suffix.length();
}

void compile_xasm_file(std::string path, Isa &isa) {
  log_fatal(!std::filesystem::exists(path), "File does not exist");

  std::ifstream in(path);
  std::ofstream out(path + ".o");

  std::string line;

  std::size_t line_count = 0;
  while (std::getline(in, line)) {
    ++line_count;
    std::istringstream iss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (iss >> token) {
      tokens.push_back(token);
    }

    if (tokens.size() == 0) {
      continue;
    }

    for (std::size_t i = 0; i < isa.size(); ++i) {
      if (tokens[0] == isa[i].mnemonic) {
        if (tokens.size() - 1 == isa[i].operands.size()) {
          std::cout << "legal\n";
          continue;
        }

        log_fatal(true, "Invalid number of operands on line " +
                            std::to_string(line_count) + ":\n" +
                            std::to_string(line_count) + ": " + line + "\n" +
                            std::string(line_count + 1, ' ') +
                            std::string(line.size(), '^'));
      }
    }
  }
}

int main(int argc, char **argv) {
  // Ensure a file path is provided
  log_fatal(argc < 2, "Provide a file path as argument");

  // Uncommented code for argument handling
  // Args args(argv + 1, argv + argc);
  // Orchestrator orchestrator(args);
  // orchestrator.process_args();
  Isa isa = load_isa("isas/origin/x32.yml");

  compile_xasm_file(argv[1], isa);

  std::string architecture_name = "xarch-origin-x32";

  std::string token = "R28";

  std::vector<std::string> root_registers;

  for (int i = 0; i < 16; ++i) {
    root_registers.push_back("R" + std::to_string(i));
  }

  return 0;
}
