#pragma once

#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

namespace linkit {

template <typename... Args> class Signal {
public:
  Signal() = default;
  Signal(const Signal &) = delete;
  Signal(Signal &&) = delete;

  template <typename Slot,
            typename = std::enable_if_t<!std::is_same_v<Slot, Signal<Args...>>>>
  auto connect(Slot &&slot) -> void {
    this->connections_.emplace_back(std::forward<Slot>(slot));
  }

  auto emit(Args &&...args) const -> void {
    for (const auto &connection : this->connections_) {
      connection(std::forward<Args>(args)...);
    }
  }

  auto disconnect() -> void { this->connections_.clear(); }

private:
  std::vector<std::function<void(Args...)>> connections_;
};

} // namespace linkit
