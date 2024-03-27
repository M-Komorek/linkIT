#include <gtest/gtest.h>

#include <linkit/signal.hpp>

namespace linkit {

class SignalTest : public ::testing::Test {
protected:
  Signal<int> signal;
};

// Test connecting slots
TEST_F(SignalTest, connecttt) { ASSERT_EQ(true, true); }

} // namespace linkit
