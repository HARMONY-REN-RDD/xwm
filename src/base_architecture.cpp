#include <xuci/base_architecture.hpp>

namespace xuci {

BaseArchitecture::BaseArchitecture() { this->_is_running = true; }

bool BaseArchitecture::is_running() const { return this->_is_running; }
void BaseArchitecture::stop_execution() { this->_is_running = false; }



} // namespace xuci
