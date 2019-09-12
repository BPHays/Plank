#include "player.h"

Player::Player(std::string name): name(name), current_state(nullptr) {}

/* Getter for the player's name */
auto Player::get_name(void) const -> const std::string& {
  return name;
}

auto Player::get_state(void) const -> std::shared_ptr<const MachineState> {
  return current_state;
}

/* Update the player state, called from the game engine */
void Player::update_state(std::shared_ptr<const MachineState> state) {
  current_state = state;
}

/* True if the player is in some game state */
auto Player::playing(void) const -> bool {
  return current_state != nullptr;
}
