#ifndef XUCI_SYK_NUMERIC_TYPE_HPP
#define XUCI_SYK_NUMERIC_TYPE_HPP

#include <xuci/syk/primitive_type.hpp>

namespace xuci::syk::types {

class NumericType : public PrimitiveType {
public:
  explicit NumericType(std::string name) : PrimitiveType(std::move(name)) {}
};

#define DECLARE_SYK_NUMERIC_TYPE(NAME)                                         \
  class SYK_##NAME : public NumericType {                                      \
  public:                                                                      \
    explicit SYK_##NAME() : NumericType(#NAME) {}                              \
  };

DECLARE_SYK_NUMERIC_TYPE(u8)
DECLARE_SYK_NUMERIC_TYPE(u16)
DECLARE_SYK_NUMERIC_TYPE(u32)
DECLARE_SYK_NUMERIC_TYPE(u64)
DECLARE_SYK_NUMERIC_TYPE(i8)
DECLARE_SYK_NUMERIC_TYPE(i16)
DECLARE_SYK_NUMERIC_TYPE(i32)
DECLARE_SYK_NUMERIC_TYPE(i64)

#undef DECLARE_SYK_NUMERIC_TYPE

} // namespace xuci::syk::types

#endif
