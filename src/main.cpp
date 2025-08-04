#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <string>

std::array<std::string, 2>
decompose_numeric_literal(const std::string &literal) {
  size_t pos = literal.find('\'');
  if (pos == std::string::npos) {
    return {"", literal};
  }

  std::string prefix = literal.substr(0, pos);
  std::string suffix = literal.substr(pos + 1);
  return {prefix, suffix};
}

bool is_string_valid_literal(const std::string &literal) {
  return literal.size() >= 2 && literal[0] == '"' &&
         literal[literal.size() - 1] == '"';
}

bool is_numeric_valid_literal(const std::string &literal) {
  auto [prefix, suffix] = decompose_numeric_literal(literal);

  if (suffix.empty()) // Empty suffix?
    return false;

  std::string allowed;
  if (prefix == "2")
    allowed = "01";
  else if (prefix == "8")
    allowed = "01234567";
  else if (prefix == "10" || prefix == "")
    allowed = "0123456789";
  else if (prefix == "16")
    allowed = "0123456789abcdefABCDEF";
  else
    return false;

  return std::all_of(suffix.begin(), suffix.end(), [&](char c) {
    return allowed.find(c) != std::string::npos;
  });
}

int main() {

  std::cout << is_numeric_valid_literal("16'2FA") << std::endl;
  std::cout << is_numeric_valid_literal("2'01\"") << std::endl;
  std::cout << is_numeric_valid_literal("8'2711") << std::endl;
  std::cout << is_numeric_valid_literal("20") << std::endl;
  return 0;
}
