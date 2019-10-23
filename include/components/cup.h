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

#ifndef INCLUDE_COMPONENTS_CUP_H_
#define INCLUDE_COMPONENTS_CUP_H_

#include <vector>

#include "components/die.h"

template<typename T, int n, typename D = Die<T, n>>
class Cup {
 private:
   std::vector<D> dice;

 public:
   Cup(std::vector<D> dice): dice(dice) {}

  /**
   * @brief Roll each of the die in the cup, updatig their cached values
   *
   * @tparam T Type representing the type on each face of the die
   */
  void roll(void) {
    std::for_each(dice.begin(), dice.end(), [](D die){die.roll();});
  }

  /**
   * @brief return the cached values for the rolled dice as a vector
   *
   * @tparam T Type representing the type on each face of the die
   *
   * @return A vector representing the set of values rolled
   */
  auto get_values(void) const -> std::vector<T> {
      std::vector<T> values;
      std::for_each(dice.begin(), dice.end(), [&](D die){values.push_back(die.roll());});
      return values;
  }

  /**
   * @brief Roll a specific die in the cup again
   *
   * @tparam T The type of the face of each die
   * @param idx The index in the dice vector to roll
   *
   * @return The value rolled
   */
  auto roll_single(std::size_t idx) -> T {
    return dice[idx].roll();
  }

  /**
   * @brief Add an additional die to the cup
   *
   * @param die The die to add
   */
  void add_die(Die<T, n> die) {
    dice.push_back(die);
  }

  /**
   * @brief Remove a die from the cup
   *
   * No real error handling right now
   */
  void remove_die(void) {
    dice.pop_back();
  }

  /**
   * @brief Get the number of dice in the cup
   *
   * @return The number of dice in the cup
   */
  auto count(void) -> int {
    return dice.size();
  }
};

#endif  // INCLUDE_COMPONENTS_CUP_H_
