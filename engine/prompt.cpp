#include <string>
#include <iostream>
#include <sstream>

#include <boost/asio.hpp>

#include "engine/prompt.h"

using boost::asio::ip::tcp;

/**
 * @brief Create a connection and send a prompt then read the response
 *
 * @param host The host to connect to
 * @param port The port on the host to connect to
 * @param request The message to send
 *
 * @return Either the response or empty if there was a failure
 */
static auto make_request(const std::string& host, const std::string& port,
    const std::string& request) -> std::optional<std::string> {

  std::stringstream response;
  try {
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve({host, port});
    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(request), error);

    for (;;) {
      std::array<char, 128> buf;
      //boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof) {
        break; // Connection closed cleanly by peer.
      } else if (error) {
        throw boost::system::system_error(error); // Some other error.
      }

      response.write(buf.data(), len);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return "ERROR";
  }

  return response.str();
}

/**
 * @brief Simplest prompt that just returns the string the player entered
 *
 * @param p The player being prompted
 * @param prompt The prompt message
 *
 * @return The player's response
 */
auto prompt_string(const Player & p, std::string prompt) -> std::string {
  res = make_request(p.get_host(), p.get_port(), prompt);
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
  res = prompt_string(p, prompt);
  return std::stoi(res);
}
