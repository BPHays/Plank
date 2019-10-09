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

#ifndef INCLUDE_DECK_H_
#define INCLUDE_DECK_H_

#include <list>
#include <string>
#include <vector>

#include "./card.h"

template<typename T>
class Deck {
  static_assert(std::is_base_of<Card, T>::value, "T must be derived from card");

 private:
  std::list<T> pile;
  std::list<T> discard_pile;

 public:
  void shuffle(void);
  auto draw_hand(int n) -> std::vector<T>;
  auto draw(void) -> T;
  void discard(T);
  void reintroduce_discard_pile(void);
  auto top(void) const -> const T&;
};

#endif  // INCLUDE_DECK_H_
