#pragma once

#include <cstdint>
#include <unordered_map>

namespace xuci {

template <typename AddressType> class Memory {
private:
  std::unordered_map<AddressType, std::uint8_t> data;

public:
  Memory() = default;

  std::uint8_t read(AddressType address) {
    return this->data.try_emplace(address, 0).first->second;
  }

  void write(AddressType address, std::uint8_t value) { this->data[address] = value; }

  void clear() { this->data.clear(); }

  
};

} // namespace xuci
