#ifndef INCLUDE_GAME_LOG_H_
#define INCLUDE_GAME_LOG_H_

#include <memory>
#include <tuple>
#include <vector>

#include "include/game_state.h"

/**
 * @brief Maintain the history of all game states and player states to roll
 * back changes
 */
class GameLog {
 private:
  std::vector<std::tuple<std::unique_ptr<GameState>, std::vector<std::unique_ptr<GameState>>>> log;

 public:
  void append(std::tuple<std::unique_ptr<GameState>, std::vector<std::unique_ptr<GameState>>> snapshot) {
    log.push_back(snapshot);
  }

  auto get_snapshot(void) -> std::tuple<std::unique_ptr<GameState>, std::vector<std::unique_ptr<GameState>>> {
    // ???
    return log.pop_back();
  }
};

#endif //  INCLUDE_GAME_LOG_H_
