#ifndef MACHINE_H
#define MACHINE_H

#include <memory>
#include <vector>

#include "machine_state.h"

class Machine {
  // The states of the state machine
  std::vector<std::unique_ptr<MachineState>> starting_states;
  std::vector<std::unique_ptr<MachineState>> ending_states;
  std::vector<std::unique_ptr<MachineState>> sinternal_states;

  // The set of players that are currently in this machine
  std::vector<std::unique_ptr<Player>> players_in_machine;
};

#endif
