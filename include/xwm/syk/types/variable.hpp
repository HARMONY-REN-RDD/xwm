#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>
#include <vector>

#include <xwm/syk/types/basic_types.hpp>

namespace xwm {

class Variable {
private:
  std::string name;
  std::vector<std::uint8_t> value;
  BaseType *type = nullptr;

public:
  Variable(const std::string &name, std::vector<std::uint8_t> value,
           BaseType *type)
      : name(name), value(value), type(type) {}

      void set_name(std::string name) { this->name = name; }
  void set_value(std::vector<std::uint8_t> value) { this->value = value; }
  void set_type(BaseType *type) { this->type = type; }

  std::string to_string() const {
    std::ostringstream oss;

    oss << "name: " << this->name << std::endl;
    oss << "value: [";
    for (int i = 0; i < this->value.size(); ++i) {
      oss << std::hex << std::setw(2) << std::setfill('0')
          << static_cast<int>(this->value[i]);
      if (i < this->value.size() - 1) {
        oss << ", ";
      }
    }
    oss << "]" << std::endl;
    oss << "type: " << this->type->get_name();

    return oss.str();
  }
};

} // namespace xwm