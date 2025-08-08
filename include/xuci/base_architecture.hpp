#pragma once

namespace xuci {

class BaseArchitecture {
private:
  bool _is_running;

public:
  BaseArchitecture();
  virtual ~BaseArchitecture() = 0;

  virtual void fetch() = 0;
  virtual void decode() = 0;
  virtual void execute() = 0;

  bool is_running() const;
  void stop_execution();
};

} // namespace xuci