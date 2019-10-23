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

#ifndef INCLUDE_STANDARD_PLAYING_CARD_H_
#define INCLUDE_STANDARD_PLAYING_CARD_H_

#include <list>
#include <string>
#include <vector>

#include "components/playing_card.h"

namespace Standard {

/**
 * @brief Standard playing card suits
 */
enum class Suits {
  HEARTS,
  CLUBS,
  DIAMONDS,
  SPADES,
};

/**
 * @brief Standard playing card faces
 */
enum class Faces {
  ACE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9,
  TEN = 10,
  JACK = 11,
  QUEEN = 12,
  KING = 13,
};

}

class StandardPlayingCard : public PlayingCard<Standard::Suits, Standard::Faces> {
 public:
  StandardPlayingCard(Standard::Suits suit, Standard::Faces face) : PlayingCard<Standard::Suits, Standard::Faces>(suit, face) {}

  /*
   * Get the integer value of the face of the card
   */
  inline constexpr auto get_face_value() const -> int {
    return static_cast<int>(get_face());
  }
};

#endif  // INCLUDE_STANDARD_PLAYING_CARD_H_
