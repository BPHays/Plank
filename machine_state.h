#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

#include <vector>

#include "game_state.h"
#include "player.h"

class Transition;

#include "transition.h"

class MachineState {
  std::vector<Transition> transitions;

  auto get_available_transitions([[maybe_unused]] Player p, [[maybe_unused]] GameState g)
    -> std::vector<Transition>;
};

#endif
