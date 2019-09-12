#include <iostream>
#include <vector>
#include <utility>

#include "engine.h"
#include "transition.h"
#include "machine.h"
#include "machine_state.h"

void red(std::shared_ptr<GameState> gs, std::shared_ptr<const MachineState> ms) {
  std::cout << "red\n";
}

void blue(std::shared_ptr<GameState> gs, std::shared_ptr<const MachineState> ms) {
  std::cout << "blue\n";
}


int main(void) {
  MachineState ms;
  std::shared_ptr<MachineState> the_state = std::make_shared<MachineState>(ms);

  std::vector<std::shared_ptr<Transition>> transitions;
  Transition t("red", the_state, red, {});
  transitions.push_back(std::make_shared<Transition>(t));
  Transition t2("blue", the_state, blue, {});
  transitions.push_back(std::make_shared<Transition>(t2));

  std::vector<std::shared_ptr<const Transition>> ts;
  for (const auto& t : transitions) {
    ts.push_back(t);
  }
  the_state->set_transitions(ts);

  std::vector<Player> players = {{"Brian"}};

  Engine eng(transitions, {the_state}, players, {}, the_state);
  eng.run();
}
