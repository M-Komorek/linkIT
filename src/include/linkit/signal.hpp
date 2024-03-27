#pragma once

#include <functional>

namespace linkit {

template <typename... Args> class Signal {
public:
  template <typename Slot> auto connect(Slot &&slot) -> void;
  auto emit(Args &&...args) const -> void;

private:
  std::vector<std::function<void(Args...)>> connections_;
};

} // namespace linkit
