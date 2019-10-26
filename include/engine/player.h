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

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <memory>
#include <string>

#include "automaton/machine_state.h"
#include "engine/io.h"

class Player {
 private:
  /* Member variables */

  // Display Name
  std::string name;

  // The information needed to set up a connection to prompt the player
  std::shared_ptr<IO> io_channel;

  // Current Game State?
  std::shared_ptr<const MachineState> current_state;

 public:
  /* Constructors */
  Player(std::string name, std::shared_ptr<IO> channel);

  /* Const member functions */
  auto get_name(void) const -> const std::string &;
  auto playing(void) const -> bool;
  auto get_state(void) const -> std::shared_ptr<const MachineState>;
  auto get_host(void) const -> const std::string &;
  auto get_port(void) const -> const std::string &;
  auto prompt(std::string req) const -> std::optional<std::string>;

  /* Non-const member functions */
  void update_state(std::shared_ptr<const MachineState> state);
};

#endif  // INCLUDE_PLAYER_H_
