#include "engine/cli_io.h"

#include <iostream>

auto CliIO::prompt(const std::string& req) const -> std::optional<std::string> {
  std::string resp;

  std::cout << req;
  std::cin >> resp;
  return resp;
}
