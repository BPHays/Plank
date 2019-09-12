#ifndef PLAYER_H
#define PLAYER_H

#include <optional>
#include <memory>
#include <string>

#include "machine_state.h"

class Player {
 private:
  /* Member variables */
  std::string name;
  std::shared_ptr<const MachineState> current_state;

  // TODO add network connection etc, here

 public:
  /* Constructors */
  Player(std::string name);

  /* Const member functions */
  auto get_name(void) const -> const std::string&;
  auto playing(void) const -> bool;
  auto get_state(void) const -> std::shared_ptr<const MachineState>;

  /* Non-const member functions */
  void update_state(std::shared_ptr<const MachineState> state);
};

#endif
