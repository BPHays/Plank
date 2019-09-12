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

#include "include/engine.h"

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

static auto prompt_for_int_choice(const std::string prompt,
                                  std::vector<std::string> options) -> int;

Engine::Engine(std::vector<std::shared_ptr<Transition>> transitions,
               std::vector<std::shared_ptr<MachineState>> states,
               std::vector<Player> players, std::shared_ptr<GameState> gs,
               std::shared_ptr<MachineState> start)
    : transitions(transitions), states(states), players(players),
      gs(std::move(gs)), start(start) {}

void Engine::run(void) {
  for (auto &player : players) {
    player.update_state(start);
  }

  // TODO(brian) this should be multithreaded when there are multiple players
  Player &player = players[0];
  for (;;) {
    // Retrieve the player's current state
    std::shared_ptr<const MachineState> state = player.get_state();

    // Get the set of transitions available to the player
    std::vector<std::shared_ptr<const Transition>> transitions =
        state->get_available_transitions(player, *gs);
    std::vector<std::string> transition_names;
    for (const auto &t : transitions) {
      transition_names.push_back(t->get_name());
    }
    int index;
    do {
      index = prompt_for_int_choice("Select a transition to take: ",
                                    transition_names);
    } while (index < 0 || index > static_cast<int>(transitions.size() - 1));

    // Perform the transition
    (*transitions[index])(gs, state);

    // Move the player to the state after the transition
    player.update_state(transitions[index]->get_target());
  }
}

static auto prompt_for_int_choice(const std::string prompt,
                                  std::vector<std::string> options) -> int {
  int x = 0;
  for (const auto &opt : options) {
    std::cout << x++ << " | " << opt << "\n";
  }
  std::cout << prompt;
  std::cin >> x;
  return x;
}
