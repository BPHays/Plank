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

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "include/engine.h"
#include "include/machine_state.h"
#include "include/transition.h"

void red(std::shared_ptr<GameState> gs,
         std::shared_ptr<const MachineState> ms) {
  std::cout << "red\n";
}

void blue(std::shared_ptr<GameState> gs,
          std::shared_ptr<const MachineState> ms) {
  std::cout << "blue\n";
}

int main(void) {
  MachineState ms;
  std::shared_ptr<MachineState> the_state = std::make_shared<MachineState>(ms);

  std::vector<std::shared_ptr<Transition>> transitions;
  Transition t("red", the_state, red, {});
  transitions.push_back(std::make_shared<Transition>(t));
  Transition t2("blue", the_state, blue, {});
  transitions.push_back(std::make_shared<Transition>(t2));

  std::vector<std::shared_ptr<const Transition>> ts;
  for (const auto &t : transitions) {
    ts.push_back(t);
  }
  the_state->set_transitions(ts);

  std::vector<Player> players = {Player{"Brian"}};

  Engine eng(transitions, {the_state}, players, {}, the_state);
  eng.run();
}
