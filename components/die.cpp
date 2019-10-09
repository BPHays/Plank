#include <random>

#include "include/components/die.h"

template<typename T, int n>
Die<T, n>::Die(std::array<T, n> sides) : sides(sides) {}

template<typename T, int n>
auto Die<T, n>::roll(void) const -> T {
  std::random_device rd;
  std::mt19937 g(rd());
  cached_value = sides[g()];
  return *cached_value;
}

template<typename T, int n>
auto Die<T, n>::get_cached_value(void) const -> T {
  return cached_value ? *cached_value : roll();
}
