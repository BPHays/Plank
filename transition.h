#ifndef TRANSITION_H
#define TRANSITION_H

#include <memory>
#include <tuple>
#include <vector>

#include "machine_state.h"

class Transition {
  MachineState target;
  std::vector<std::unique_ptr<MachineState>> dependant_epsilons;

  virtual auto update(GameState g, MachineState m)
    -> std::tuple<GameState, MachineState, std::vector<Player>> = 0;
};

#endif //  TRANSITION_H
