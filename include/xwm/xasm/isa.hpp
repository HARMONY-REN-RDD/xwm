#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include <cstdint>

#include <yaml-cpp/yaml.h>

struct Instruction {
  std::string mnemonic;
  std::vector<std::string> operands;
  std::string description;
};

using Isa = std::unordered_map<std::uint16_t, Instruction>;

inline Isa load_isa(std::string path) {
  YAML::Node config = YAML::LoadFile(path)["instructions"];

  Isa instructions;

  for (std::size_t i = 0; i < config.size(); ++i) {
    Instruction instruction;
    instruction.mnemonic = config[i]["mnemonic"].as<std::string>();

    if (config[i]["operands"]) {
      instruction.operands =
          config[i]["operands"].as<std::vector<std::string>>();
    }

    if (config[i]["description"]) {
      instruction.description = config[i]["description"].as<std::string>();
    }

    instructions[i] = instruction;
  }

  return instructions;
}
