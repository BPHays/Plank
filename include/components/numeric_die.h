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

#ifndef INCLUDE_NUMERIC_DIE_H_
#define INCLUDE_NUMERIC_DIE_H_

#include <string>
#include <utility>
#include <array>
#include <tuple>

#include "components/die.h"

template<int n>
class NumericDie : public Die<int, n> {
 public:
  NumericDie(void) : Die<int, n>(make_faces()) {}
 private:
  virtual auto to_string(void) const -> std::string {
    return "";
  }
  constexpr static auto make_faces(void) -> std::array<int, n> {
    std::array<int, n> a; std::iota(a.begin(), a.end(), 1);
    return a;
  }
};

#endif  // INCLUDE_NUMErIC_DIE_H_
