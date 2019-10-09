#include "include/components/playing_card.h"

template<typename S, typename F>
PlayingCard<S, F>::PlayingCard(S suit, F face): suit(suit), face(face) {}


template<typename S, typename F>
auto PlayingCard<S, F>::genearate_deck(std::vector<S> suits, std::vector<F> faces) -> std::list<PlayingCard> {
  std::list<PlayingCard> deck;
  for (const auto& s : suits) {
    for (const auto& f : faces) {
      deck.push_back(s, f);
    }
  }
  return deck;
}
