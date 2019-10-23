#include "gtest/gtest.h"

#include "components/standard_playing_card.h"

namespace {

class CardsTest : public ::testing::Test {
};

TEST_F(CardsTest, PlayingCardTest) {
  StandardPlayingCard ace_of_spades{StandardPlayingCard::Suits::SPADES, StandardPlayingCard::Faces::ACE};
  EXPECT_EQ(static_cast<const int>(ace_of_spades.get_face()), 1);
}

}  // namespace
