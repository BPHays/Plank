#include <string>
#include <iostream>
#include <optional>
#include <sstream>

#include "engine/prompt.h"

/**
 * @brief Simplest prompt that just returns the string the player entered
 *
 * @param p The player being prompted
 * @param prompt The prompt message
 *
 * @return The player's response
 */
auto prompt_string(const Player & p, std::string req) -> std::string {
  std::optional<std::string> res = p.prompt(req);
  if (res) {
    return *res;
  } else {
    // TODO think about the best way to handle failures here
    std::cerr << "Failed to get string :(\n";
    return "";
  }
}

/**
 * @brief Prompt that returns an integer value
 *
 * @param p The player being prompted
 * @param prompt The prompt message
 *
 * @return The player's response as an integer
 */
auto prompt_integer(const Player & p, std::string prompt) -> int {
  std::string res = prompt_string(p, prompt);
  return std::stoi(res);
}
