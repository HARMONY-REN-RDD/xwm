#ifndef XUCI_SYK_BASE_TYPE_HPP
#define XUCI_SYK_BASE_TYPE_HPP

#include <string>

namespace xuci::syk::types {

struct BaseType {
  std::string name;

  explicit BaseType(std::string name) : name(std::move(name)) {}
  virtual ~BaseType() = default;
};

} // namespace xuci::syk::types

#endif