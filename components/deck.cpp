#include "include/components/deck.h"

#include <algorithm>
#include <random>
#include <vector>

template<typename T>
void Deck<T>::shuffle(void) {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(pile.begin(), pile.end(), g);
}

template<typename T>
auto Deck<T>::draw_hand(int n) -> std::vector<T>{

  std::vector<T> hand;
  hand.reserve(n);
  for (int i = 0; i < n; i++) {
    hand.push_back(pile.pop_front());
  }
  return hand;
}

template<typename T>
auto Deck<T>::draw(void) -> T {
  return pile.pop_front();
}

template<typename T>
void Deck<T>::discard(T card) {
  discard_pile.push_front(card);
}

template<typename T>
void Deck<T>::reintroduce_discard_pile(void) {
  pile.insert(discard_pile);
}

template<typename T>
auto Deck<T>::top(void) const -> const T& {
  return pile.front();
}
