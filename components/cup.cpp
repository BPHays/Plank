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

#include "include/components/cup.h"

/**
 * @brief Roll each of the die in the cup, updatig their cached values
 *
 * @tparam T Type representing the type on each face of the die
 */
template<typename T>
void Cup::roll(void) {
  std::for_each(dice.begin(), dice.end(), Die::roll);
}

/**
 * @brief return the cached values for the rolled dice as a vector
 *
 * @tparam T Type representing the type on each face of the die
 *
 * @return A vector representing the set of values rolled
 */
template<typename T>
auto Cup::get_values(void) const -> std::vector<T> {
    std::vector<T> values;
    std::transform(dice.begin(), dice.end(), std::back_inserter(values), Die::get_cached_value);
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
template<typename T>
auto Cup::roll_single(std::size_t idx) -> T {
  return dice[i].roll();
}
