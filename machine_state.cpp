#include "machine_state.h"

auto MachineState::get_available_transitions([[maybe_unused]] Player p, [[maybe_unused]] const GameState& g) const
  -> std::vector<std::shared_ptr<const Transition>> {
    return transitions;
}

void MachineState::set_transitions(std::vector<std::shared_ptr<const Transition>> transitions) {
  this->transitions = transitions;
}

