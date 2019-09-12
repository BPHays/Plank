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
    std::shared_ptr<const MachineState> state = player.get_state();
    std::vector<std::shared_ptr<const Transition>> transitions =
        state->get_available_transitions(player, *gs);
    int i = 0;
    for (const auto &t : transitions) {
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
