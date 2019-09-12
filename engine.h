#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <vector>

#include "game_state.h"
#include "machine_state.h"
#include "player.h"
#include "transition.h"

class Engine {
 private:
  std::vector<std::shared_ptr<Transition>> transitions;
  std::vector<std::shared_ptr<MachineState>> states;
  std::vector<Player> players;
  std::shared_ptr<GameState> gs;
  std::shared_ptr<MachineState> start;

 public:
  Engine(std::vector<std::shared_ptr<Transition>> transitions, std::vector<std::shared_ptr<MachineState>> states, std::vector<Player> players, std::shared_ptr<GameState> gs, std::shared_ptr<MachineState> start);

  void run(void);
};

#endif
