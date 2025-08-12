#include <xuci/log.hpp>
#include <xuci/orchestrator.hpp>

namespace xuci {

void Orchestrator::process_args() {
  std::string cmd = this->args->at(0);

  if (cmd == "-e") {
    log_fatal(this->args->size() < 2, "Provide the file of the architecture");

    this->architecture = this->load_architecture(this->args->at(1));
    
    do {
      this->architecture->fetch();
      this->architecture->decode();
      this->architecture->execute();
    } while (this->architecture->is_running());
    
    return;
  }

  log_fatal(1, "Unknown command");
}

} // namespace xuci
