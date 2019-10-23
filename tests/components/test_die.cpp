#include "gtest/gtest.h"

#include "components/coin.h"
#include "components/cup.h"
#include "components/die.h"
#include "components/numeric_die.h"

namespace {

class DieTest : public ::testing::Test {
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(DieTest, NumericDieTest) {
  NumericDie<6> d6;
  for (int i = 0; i < 20; i++) {
    int val = d6.roll();
    EXPECT_TRUE(0 < val && val <= 6);
  }
  int roll = d6.roll();
  int cached = d6.get_cached_value();
  EXPECT_EQ(roll, cached);
}

TEST_F(DieTest, CoinTest) {
  Coin penny;
  for (int i = 0; i < 20; i++) {
    coin_sides val = penny.roll();
    EXPECT_TRUE(val == coin_sides::heads || val == coin_sides::tails);
  }
  coin_sides roll = penny.roll();
  coin_sides cached = penny.get_cached_value();
  EXPECT_EQ(roll, cached);
}

TEST_F(DieTest, CupTest) {
  std::vector<NumericDie<6>> d6s{{}, {}, {}};
  Cup<int, 6, NumericDie<6>> cup(d6s);
  cup.roll();
  for(auto vals = cup.get_values(); auto val : vals) {
    EXPECT_TRUE(0 < val && val <= 6);
  }
}

}  // namespace
