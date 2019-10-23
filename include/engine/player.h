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
#include <optional>
#include <string>

#include "./machine_state.h"

class Player {
 private:
  /* Member variables */

  // Display Name
  std::string name;

  // Current Game State?
  std::shared_ptr<const MachineState> current_state;

  // TODO(brian) add network connection etc, here
  // Netowork Information
  // Hostname?
  // Port?

 public:
  /* Constructors */
  explicit Player(std::string name);

  /* Const member functions */
  auto get_name(void) const -> const std::string &;
  auto playing(void) const -> bool;
  auto get_state(void) const -> std::shared_ptr<const MachineState>;

  /* Non-const member functions */
  void update_state(std::shared_ptr<const MachineState> state);

  //auto disconnect(void);
  // TODO(brian) update with network info. This function should take the
  // netowrk info for a reconnecting player
  //auto reconnect(void);
};

#endif  // INCLUDE_PLAYER_H_
