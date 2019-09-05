#include "machine_state.h"

auto MachineState::get_available_transitions([[maybe_unused]] Player p, [[maybe_unused]] GameState g)
  -> std::vector<Transition> {
    return transitions;
}
