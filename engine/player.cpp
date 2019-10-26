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

#include <memory>
#include <string>

#include "engine/player.h"

Player::Player(std::string name, std::shared_ptr<IO> channel) : name(name), io_channel(std::move(channel)), current_state(nullptr) {}

/* Getter for the player's name */
auto Player::get_name(void) const -> const std::string & { return name; }

/* Getter for the player's current state */
auto Player::get_state(void) const -> std::shared_ptr<const MachineState> {
  return current_state;
}

/* Update the player state, called from the game engine */
void Player::update_state(std::shared_ptr<const MachineState> state) {
  current_state = state;
}

/* True if the player is in some game state */
auto Player::playing(void) const -> bool { return current_state != nullptr; }


/**
 * @brief Connect to the player over the players io channel and prompt them for
 * the requested information
 *
 * @param req the request message
 *
 * @return the player's response
 */
auto Player::prompt(std::string req) const -> std::optional<std::string> {
  return io_channel->prompt(req);
}
