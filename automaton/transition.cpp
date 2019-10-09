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

#include "include/transition.h"

#include <memory>
#include <string>
#include <vector>

#include "include/machine_state.h"

Transition::Transition(
    std::string name, std::shared_ptr<const MachineState> target,
    std::function<bool(std::shared_ptr<GameState>,
                       std::shared_ptr<const MachineState>)>
        execute,
    std::vector<std::shared_ptr<MachineState>> dependant_epsilons)
    : name(name), target(target), execute(execute),
      dependant_epsilons(dependant_epsilons) {}

auto Transition::get_name(void) const -> const std::string & { return name; }

auto Transition::get_target(void) const -> std::shared_ptr<const MachineState> {
  return target;
}

// Calling a transition executes the code in the transition's execute
// function that was provided by the user
bool Transition::operator()(std::shared_ptr<GameState> gs,
                            std::shared_ptr<const MachineState> ms) const {
  return execute(gs, ms);
}
