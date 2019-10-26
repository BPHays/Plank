#ifndef INCLUDE_ENGINE_CLI_IO_H_
#define INCLUDE_ENGINE_CLI_IO_H_
#include "io.h"

class CliIO : IO {
 public:
  auto prompt(const std::string& req) const -> std::optional<std::string>;
};

#endif //  INCLUDE_ENGINE_CLI_IO_H_
