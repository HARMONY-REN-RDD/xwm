#pragma once

#include <string>

namespace xwm {

class BaseType {
protected:
  std::string name;

public:
  BaseType(const std::string &name) { this->name = name; }

  virtual ~BaseType() = default;

  const std::string &get_name() const { return this->name; }
};

class Primitive : public BaseType {
public:
  Primitive(const std::string &name) : BaseType(name) {}
  virtual ~Primitive() = default;
};

class Aggregate : public BaseType {
public:
  Aggregate(const std::string &name) : BaseType(name) {}
  virtual ~Aggregate() = default;
};

} // namespace xwm
