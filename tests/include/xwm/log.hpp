#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

namespace xwm {

// ANSI color codes
constexpr char INFO_COLOR[] = "\033[36m";    // Cyan
constexpr char WARNING_COLOR[] = "\033[33m"; // Yellow
constexpr char ERROR_COLOR[] = "\033[31m";   // Red
constexpr char FATAL_COLOR[] = "\033[1;31m"; // Bold red
constexpr char RESET_COLOR[] = "\033[0m";    // Reset

inline void log_info(bool condition, const std::string &message) {
  if (condition) {
    std::cout << "[" << INFO_COLOR << "INFO" << RESET_COLOR << "] " << message
              << std::endl;
  }
}

inline void log_warning(bool condition, const std::string &message) {
  if (condition) {
    std::cerr << "[" << WARNING_COLOR << "WARNING" << RESET_COLOR << "] "
              << message << std::endl;
  }
}

inline void log_error(bool condition, const std::string &message) {
  if (condition) {
    std::cerr << "[" << ERROR_COLOR << "ERROR" << RESET_COLOR << "] " << message
              << std::endl;
  }
}

inline void log_fatal(bool condition, const std::string &message) {
  if (condition) {
    std::cerr << "[" << FATAL_COLOR << "FATAL" << RESET_COLOR << "] " << message
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

} // namespace xwm
