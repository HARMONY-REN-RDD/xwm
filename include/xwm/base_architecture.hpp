#pragma once

#include <string>
#ifdef _WIN32
#include <windows.h>
#define xwm_EXPORT extern "C" __declspec(dllexport)
#else
#include <dlfcn.h>
#define xwm_EXPORT extern "C"
#endif

#include <vector>

namespace xwm {

class BaseArchitecture {
protected:
  bool _is_running;
  std::vector<std::string> _args;

public:
  BaseArchitecture();
  virtual ~BaseArchitecture() = default;

  inline void set_args(std::vector<std::string> args) { this->_args = args; }
  virtual void fetch() = 0;
  virtual void decode() = 0;
  virtual void execute() = 0;
  virtual void run() = 0;

  bool is_running() const;
  void stop_execution();
};

} // namespace xwm
