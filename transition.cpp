#include "transition.h"

#include <memory>
#include <string>
#include <vector>

#include "machine_state.h"

Transition::Transition(std::string name, std::shared_ptr<const MachineState> target, std::function<void(std::shared_ptr<GameState>, std::shared_ptr<const MachineState>)> execute, std::vector<std::shared_ptr<MachineState>> dependant_epsilons) : name(name), target(target), execute(execute), dependant_epsilons(dependant_epsilons) {}

auto Transition::get_name(void) const -> const std::string& {
  return name;
}

auto Transition::get_target(void) const -> std::shared_ptr<const MachineState> {
  return target;
}

// Calling a transition executes the code in the transition's execute
// function that was provided by the user
void Transition::operator()(std::shared_ptr<GameState> gs, std::shared_ptr<const MachineState> ms) const {
  execute(gs, ms);
}
