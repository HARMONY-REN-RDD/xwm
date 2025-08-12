#include <xuci/log.hpp>
#include <xuci/orchestrator.hpp>




namespace xuci {

using LoadArchitectureFunc = BaseArchitecture *(*)(Orchestrator *);

BaseArchitecture *Orchestrator::load_architecture(const std::string &path) {
  LoadArchitectureFunc func = nullptr;

  std::cout << "[INFO] Loading shared library '" << path << "'\n";

#ifdef __linux__
  handle = dlopen(path.c_str(), RTLD_LAZY);
  log_fatal(!handle, "Could not load shared library");

  func = (LoadArchitectureFunc)dlsym(handle, "load_architecture");
  log_fatal(!func, "Could not find symbol 'load_architecture'");

#elif defined(_WIN32)
  handle = (void *)LoadLibraryA(path.c_str());

  if (!handle) {
    DWORD err = GetLastError();
    std::cerr << "[ERROR] LoadLibrary failed with error code: " << err << "\n";
    log_fatal(true, "Could not load shared library");
  }

  log_fatal(!handle, "Could not load shared library");

  func = (LoadArchitectureFunc)(uintptr_t)GetProcAddress((HMODULE)handle,
                                                         "load_architecture");

  log_fatal(!func, "Could not find symbol 'load_architecture'");

#else
  log_fatal(true, "Shared library loading not implemented on this platform");
  return nullptr;
#endif

  return func(this);
}

} // namespace xuci
