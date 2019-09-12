#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

#include <memory>
#include <vector>

class MachineState;
class Transition;
class Player;

#include "game_state.h"
#include "player.h"
#include "transition.h"

class MachineState {
 private:
  std::vector<std::shared_ptr<const Transition>> transitions;

 public:
  auto get_available_transitions([[maybe_unused]] Player p, [[maybe_unused]] const GameState& g) const
    -> std::vector<std::shared_ptr<const Transition>>;

  void set_transitions(std::vector<std::shared_ptr<const Transition>> transitions);
};

#endif
