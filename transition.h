#ifndef TRANSITION_H
#define TRANSITION_H

#include <functional>
#include <memory>
#include <tuple>
#include <vector>

#include "machine_state.h"

class Transition {
 private:
  std::string name;
  std::shared_ptr<const MachineState> target;
  std::vector<std::shared_ptr<MachineState>> dependant_epsilons;

 public:
  Transition(std::string name, std::shared_ptr<const MachineState> target, std::function<void(std::shared_ptr<GameState>, std::shared_ptr<const MachineState>)> execute, std::vector<std::shared_ptr<MachineState>> dependant_epsilons);
  auto get_name(void) const -> const std::string&;
  auto get_target(void) const -> std::shared_ptr<const MachineState>;

  std::function<void(std::shared_ptr<GameState>, std::shared_ptr<const MachineState>)> execute;
  void operator()(std::shared_ptr<GameState> gs, std::shared_ptr<const MachineState> ms) const;
};

#endif //  TRANSITION_H
