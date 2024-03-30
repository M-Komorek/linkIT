#pragma once

#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

namespace linkit
{

template <typename... Args>
class Signal
{
public:
    Signal();
    Signal(const Signal&) = delete;
    Signal(Signal&&) = delete;

    template <typename Slot, typename = std::enable_if_t<!std::is_same_v<Slot, Signal<Args...>>>>
    auto connect(Slot&& slot) -> void;
    auto disconnect() -> void;

    auto emit(Args&&...args) const -> void;

private:
    std::vector<std::function<void(Args...)>> connections_;
};

template <typename... Args>
Signal<Args...>::Signal() : connections_{}
{
}

template <typename... Args>
template <typename Slot, typename>
auto Signal<Args...>::connect(Slot&& slot) -> void
{
    this->connections_.emplace_back(std::forward<Slot>(slot));
}

template <typename... Args>
auto Signal<Args...>::disconnect() -> void
{
    this->connections_.clear();
}

template <typename... Args>
auto Signal<Args...>::emit(Args&&...args) const -> void
{
    for (const auto& connection : this->connections_)
    {
        connection(std::forward<Args>(args)...);
    }
}

} // namespace linkit
