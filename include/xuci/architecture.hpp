#ifndef XUCI_ARCHITECTURE_HPP
#define XUCI_ARCHITECTURE_HPP

#include <cstdint>
#include <string>
#include <vector>


namespace xuci {

class Architecture {
protected:
  bool running = true;

public:
  virtual void fetch() = 0;
  virtual void decode() = 0;
  virtual void execute() = 0;

  inline bool is_running() { return this->running; }
};

} // namespace xuci

#endif