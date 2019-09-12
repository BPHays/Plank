#include "engine.h"

#include <utility>
#include <iostream>

Engine::Engine(std::vector<std::shared_ptr<Transition>> transitions, std::vector<std::shared_ptr<MachineState>> states, std::vector<Player> players, std::shared_ptr<GameState> gs, std::shared_ptr<MachineState> start): transitions(transitions), states(states), players(players), gs(std::move(gs)), start(start) {}

void Engine::run(void) {
  for (auto& player : players) {
    player.update_state(start);
  }

  // TODO this should be multithreaded when there are multiple players
  Player & player = players[0];
  for (;;) {
    std::shared_ptr<const MachineState> state = player.get_state();
    std::vector<std::shared_ptr<const Transition>> transitions = state->get_available_transitions(player, *gs);
    int i = 0;
    for (const auto & t : transitions) {
      std::cout << i++ << " | " << t->get_name() << "\n";
    }
    std::cout << "Select a transition to take: ";
    int index;
    std::cin >> index;

    std::shared_ptr x = transitions[index];
    const Transition y = *x;
    y.execute(gs, state);
    player.update_state(y.get_target());
  }
}
