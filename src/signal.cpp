#include "link_it/signal.hpp"

#include <utility>

namespace link_it {

template <typename... Args>
template <typename Slot>
auto Signal<Args...>::connect(Slot &&slot) -> void {
  this->connections_.emplace_back(std::forward<Slot>(slot));
}

template <typename... Args>
auto Signal<Args...>::emit(Args &&...args) const -> void {
  for (const auto &connection : this->connections_) {
    connection(std::forward<Args>(args)...);
  }
}

} // namespace link_it
