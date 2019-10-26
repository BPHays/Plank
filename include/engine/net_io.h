#ifndef INCLUDE_ENGINE_NET_IO_H_
#define INCLUDE_ENGINE_NET_IO_H_
#include "io.h"

class NetIO : IO {
 private:
  std::string host;
  std::string port;

 public:
  NetIO(std::string host, std::string port);

  auto prompt(const std::string& req) const -> std::optional<std::string>;
};

#endif //  INCLUDE_ENGINE_NET_IO_H_
