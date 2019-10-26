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

#ifndef INCLUDE_MACHINE_STATE_H_
#define INCLUDE_MACHINE_STATE_H_

#include <memory>
#include <vector>

class MachineState;
class Transition;
class Player;

#include "components/game_state.h"
#include "engine/player.h"
#include "automaton/transition.h"

class MachineState {
 private:
  std::vector<std::shared_ptr<const Transition>> transitions;

 public:
  auto get_available_transitions([[maybe_unused]] const std::unique_ptr<Player>& p,
                                 [[maybe_unused]] const GameState &g) const
      -> std::vector<std::shared_ptr<const Transition>>;

  void set_transitions(
      std::vector<std::shared_ptr<const Transition>> transitions);
};

#endif  // INCLUDE_MACHINE_STATE_H_
