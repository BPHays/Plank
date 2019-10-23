/*
 * The MIT License (MIT) 
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

#ifndef INCLUDE_PLAYING_CARD_H_
#define INCLUDE_PLAYING_CARD_H_

#include <list>
#include <string>
#include <vector>

#include "components/card.h"

/**
 * @brief The Playing Card representing a combination of suit and face
 *
 * @tparam S The type of the cards suits
 * @tparam F The type of the cards faces
 */
template<typename S, typename F>
class PlayingCard : Card {
 private:
  S suit;
  F face;

 public:
  /**
   * @brief Create a playing card with a given suit and face
   *
   * @param suit The suit of the card
   * @param face The face of the card
   */
  PlayingCard(S suit, F face): suit(suit), face(face) {}

  /**
   * @brief Extract and return the card's suit
   *
   * @return The suit of the card
   */
  auto constexpr get_suit(void) const -> S {
    return suit;
  }

  /**
   * @brief Extract and return the card's face
   *
   * @return The face of the card
   */
  auto constexpr get_face(void) const -> F {
    return face;
  }

  /**
   * @brief Extract and return both the suit and the face of the card
   *
   * @return A pair of the suit and face of the card
   */
  auto constexpr get_values(void) const -> std::pair<S, F> {
    return {suit, face};
  }

  /**
   * @brief Generate a deck of cards with a pair of each suit and face in the
   * deck. The size of the deck is |S| * |F|
   *
   * @param suits The set of suits to use
   * @param faces The set of faces to use
   *
   * @return A list of the cards
   *
   * TODO should this be a deck?
   */
  auto static genearate_deck(std::vector<S> suits, std::vector<F> faces) -> std::list<PlayingCard> {
    std::list<PlayingCard> deck;
    for (const auto& s : suits) {
      for (const auto& f : faces) {
        deck.push_back(s, f);
      }
    }
    return deck;
  }

  /*
   * Keep a reference to the paramater types to make it easier for users
   * to access those types
   */
  typedef S Suits;
  typedef F Faces;
};

#endif  // INCLUDE_PLAYING_CARD_H_
