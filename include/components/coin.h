#include "components/die.h"

enum class coin_sides {
  heads = 0,
  tails = 1,
};

class Coin : public Die<coin_sides, 2> {
 public:
  Coin(void) : Die<coin_sides, 2>({coin_sides::heads, coin_sides::tails}) {}

 private:
  auto flip(void) const -> coin_sides {
    return roll();
  }
};
