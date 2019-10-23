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

#include <algorithm>
#include <list>
#include <random>
#include <string>
#include <vector>

#include "components/card.h"

/**
 * @brief A container for cards, which contians common helpers for card deck
 * operations
 *
 * @tparam T The type of card being contained
 */
template<typename T>
class Deck {
  static_assert(std::is_base_of<Card, T>::value, "T must be derived from card");

 private:
  /**
   * @brief The pile to retrieve the next drawn card from
   */
  std::list<T> pile;

  /**
   * @brief The pile to place the next discarded card into
   */
  std::list<T> discard_pile;

 public:
  /**
   * @brief Shuffle the deck
   */
  void shuffle(void) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(pile.begin(), pile.end(), g);
  }

  /**
   * @brief Helper to drawn n cards at a time
   *
   * @param n The number of cards to draw
   *
   * @return The n cards drawn from the deck
   *
   * TODO error handling
   */
  auto draw_hand(int n) -> std::vector<T>{
    std::vector<T> hand;
    hand.reserve(n);
    for (int i = 0; i < n; i++) {
      hand.push_back(pile.pop_front());
    }
    return hand;
  }

  /**
   * @brief Retrieve a single card from the pile
   *
   * @return The card that was drawn
   */
  auto draw(void) -> T {
    return pile.pop_front();
  }

  /**
   * @brief Place a single card int the deck's discard pile
   *
   * @param card The card to discard
   */
  void discard(T card) {
    discard_pile.push_front(card);
  }

  /**
   * @brief Place the cards in the discard pile back into the regular pile
   */
  void reintroduce_discard_pile(void) {
    pile.insert(discard_pile);
  }

  /**
   * @brief Peek at the top card
   *
   * @return The card on the top of the draw pile
   */
  auto top(void) const -> const T& {
    return pile.front();
  }
};

#endif  // INCLUDE_DECK_H_
