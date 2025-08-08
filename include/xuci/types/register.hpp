#pragma once

#include <xuci/types/memory.hpp>

#include <iomanip>
#include <sstream>
#include <string>

namespace xuci {

template <std::uint8_t _n_bytes> class Register : public Memory<std::uint8_t> {
public:
  static constexpr std::uint8_t n_bytes = _n_bytes;

  Register() = default;

  std::string to_hex() {
    std::ostringstream oss;

    for (auto i = 0; i < this->n_bytes; i++) {
      oss << std::hex << std::setw(2) << std::setfill('0')
          << static_cast<int>(this->read(i));
    }

    return oss.str();
  }
};

} // namespace xuci