#include <string>
#include <iostream>
#include <sstream>

#include <boost/asio.hpp>

#include "engine/net_io.h"

using boost::asio::ip::tcp;

/**
 * @brief Create a host 
 *
 * @param host The IP/hostname of the player's client
 * @param port The port the player's client is listening on
 */
NetIO::NetIO(std::string host, std::string port) : host(host), port(port) {}

/**
 * @brief Create a connection and send a prompt then read the response
 *
 * @param request The message to send
 *
 * @return Either the response or empty if there was a failure
 */
auto NetIO::prompt(const std::string& req) const -> std::optional<std::string> {

  std::stringstream response;
  try {
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve({host, port});
    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(req), error);

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

