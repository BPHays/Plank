/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Brian Hays
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INCLUDE_DIE_H_
#define INCLUDE_DIE_H_

#include <array>
#include <iostream>
#include <optional>
#include <random>

template<typename T, int n>
class Die {
 private:
  /* The set of sides on the die each of type T */
  std::array<T, n> sides;
  /* The vlaue shown by the last roll of the die */
  mutable std::optional<T> cached_value;

 public:
  /* Generate a die from the set of sides on the die */
  Die(std::array<T, n> sides) : sides(sides), cached_value(std::nullopt) {}

  /**
   * @brief pick a side at random, and update the cache
   *
   * @return The value of the side that was chosen
   */
  auto roll(void) const -> T {
    std::random_device rd;
    std::mt19937 g(rd());
    cached_value = std::make_optional(sides[g() % n]);
    return *cached_value;
  }

  /**
   * @brief Maintian the last rolled value on the die
   * @return The last value rolled by the die
   */
  auto get_cached_value(void) const -> T {
    return cached_value ? *cached_value : roll();
  }

 private:
  virtual auto to_string(void) const -> std::string {
    return "";
  }
};

#endif  // INCLUDE_DIE_H_
