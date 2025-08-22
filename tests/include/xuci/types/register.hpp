#pragma once

#include <xwm/types/memory.hpp>

#include <iomanip>
#include <sstream>
#include <string>

namespace xwm {

template <std::uint8_t _n_bytes> class Register : public Memory<std::uint8_t> {
public:
  static constexpr std::uint8_t n_bytes = _n_bytes;

  Register() = default;

  std::string to_hex(bool little = true) const {
    std::ostringstream oss;
    if (little) {
      for (int i = 0; i < n_bytes; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(this->read(i));
      }
    } else {
      for (int i = n_bytes - 1; i >= 0; --i) {
        oss << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(this->read(i));
      }
    }
    return oss.str();
  }

  std::uint64_t to_unsigned(bool little = true) {
    uint64_t result = 0;
    if (little) {
      for (int i = 0; i < n_bytes; ++i) {
        result |= static_cast<uint64_t>(this->read(i)) << (8 * i);
      }
    } else { // Big endian
      for (int i = 0; i < n_bytes; ++i) {
        result = (result << 8) | this->read(i);
      }
    }
    return result;
  }

  void increment() {
    for (int i = 0; i < n_bytes; ++i) {
      uint8_t val = this->read(i);
      if (val == 0xFF) {
        this->write(i, 0x00);
      } else {
        this->write(i, val + 1);
        break;
      }
    }
  }

  void decrement() {
    for (int i = 0; i < n_bytes; ++i) {
      uint8_t val = this->read(i);
      if (val == 0x00) {
        this->write(i, 0xFF);
      } else {
        this->write(i, val - 1);
        break;
      }
    }
  }

  void add(int64_t n) {
    int64_t val = static_cast<int64_t>(to_unsigned());
    val += n;
    uint64_t uval = static_cast<uint64_t>(val);

    for (int i = 0; i < n_bytes; ++i) {
      this->write(i, uval & 0xFF);
      uval >>= 8;
    }
  }
};

} // namespace xwm