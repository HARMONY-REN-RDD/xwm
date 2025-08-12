#include <xuci/orchestrator.hpp>

xuci::Orchestrator::Orchestrator(Args &args) : args(args) {}

xuci::Orchestrator::~Orchestrator() {
  if (this->architecture) {
    delete this->architecture;
  }

  if (handle) {
#ifdef __linux__
    dlclose(handle);
#elif defined(_WIN32)

    FreeLibrary((HMODULE)handle);
#else
    log_fatal(true,
              "Shared library unloading not implemented on this platform");
#endif
  }

  handle = nullptr;
}
