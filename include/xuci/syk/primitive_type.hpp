#ifndef XUCI_SYK_PRIMITIVE_TYPE_HPP
#define XUCI_SYK_PRIMITIVE_TYPE_HPP

#include <xuci/syk/base_type.hpp>

namespace xuci::syk::types {

class PrimitiveType : public BaseType {
public:
  explicit PrimitiveType(std::string name) : BaseType(std::move(name)) {}
};

} // namespace xuci::syk::types

#endif