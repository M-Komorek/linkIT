#include <gtest/gtest.h>

#include <linkit/signal.hpp>

namespace linkit {

TEST(SignalTest, singleConnection) {
  auto value = int{0};

  auto valueChange = Signal<int>{};
  valueChange.connect([&value](int x) { value = x; });

  valueChange.emit(997);

  EXPECT_EQ(value, 997);
}

TEST(SignalTest, multipleConnections) {
  auto count = int{0};

  auto signal = Signal<int>{};
  signal.connect([&count](const auto x) { count += x; });
  signal.connect([&count](const auto x) { count += x; });

  signal.emit(10);

  EXPECT_EQ(count, 20);
}

TEST(SignalTest, connectDifferentTypesWithSingleSignal) {
  auto intArg = int{0};
  auto floatArg = float{0};
  auto stringArg = std::string{};

  auto differentTypesSignal = Signal<int, float, std::string>{};
  differentTypesSignal.connect([&intArg, &floatArg, &stringArg](
                                   const int intValue, const float floatValue,
                                   const std::string &stringValue) {
    intArg = intValue;
    floatArg = floatValue;
    stringArg = stringValue;
  });

  differentTypesSignal.emit(5, 3.14f, "Hello");

  EXPECT_EQ(intArg, 5);
  EXPECT_FLOAT_EQ(floatArg, 3.14f);
  EXPECT_EQ(stringArg, "Hello");
}

TEST(SignalTest, disconnectAllSlots) {
  auto count = int{0};

  auto signal = Signal<int>{};
  signal.connect([&count](const auto x) { count += x; });
  signal.connect([&count](const auto x) { count += x; });

  signal.emit(10);
  EXPECT_EQ(count, 20);

  signal.disconnect();
  signal.emit(10);
  EXPECT_EQ(count, 20);
}

} // namespace linkit
