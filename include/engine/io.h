#ifndef INCLUDE_ENGINE_IO_H_
#define INCLUDE_ENGINE_IO_H_

#include <optional>
#include <string>

class IO {
 public:
  virtual auto prompt(const std::string& req) const -> std::optional<std::string> = 0;
  inline virtual ~IO() {}
};

#endif //  INCLUDE_ENGINE_IO_H_
