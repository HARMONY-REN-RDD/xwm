#ifndef XUCI_SYK_CLASS_TYPE_HPP
#define XUCI_SYK_CLASS_TYPE_HPP

#include <xuci/syk/base_type.hpp>

namespace xuci::syk::types {

class ClassType : public BaseType {
public:
  explicit ClassType(std::string name) : BaseType(std::move(name)) {}
};

} // namespace xuci::syk::types

#endif