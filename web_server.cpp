#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

const std::string htmlResponse = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\nContent-Type: text/html\r\n\r\nHello, World!";

int main() {
    io_service io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080)); // Port 8080

    while (true) {
        tcp::socket socket(io);
        acceptor.accept(socket);

        boost::system::error_code ignored_error;
        write(socket, buffer(htmlResponse), ignored_error);
    }

    return 0;
}

