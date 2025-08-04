#ifndef XUCI_SYK_LOGICAL_TYPE_HPP
#define XUCI_SYK_LOGICAL_TYPE_HPP

#include <xuci/syk/primitive_type.hpp>

namespace xuci::syk::types {

class LogicalType : public PrimitiveType {
public:
  explicit LogicalType(std::string name) : PrimitiveType(std::move(name)) {}
};

class SYK_bool : public LogicalType {
public:
  explicit SYK_bool() : LogicalType("bool") {}
};

} // namespace xuci::syk::types

#endif
