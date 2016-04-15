#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <chrono>
#include <boost/asio/steady_timer.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

int main()
{
//    while(1) {
//        boost::asio::io_service io;
//        boost::asio::steady_timer t(io,std::chrono::milliseconds(1000));
//        std::string message1 = make_daytime_string();
//        std::cout<<message1<<std::endl;
//        t.wait();

//    }
  try
  {
    boost::asio::io_service io_service;

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 20000));

    for (;;)
    {
      tcp::socket socket(io_service);
      acceptor.accept(socket);
      while(1) {
      std::string message = make_daytime_string();
      std::cout<<message<<std::endl;

      boost::system::error_code ignored_error;

          boost::asio::io_service io;
          boost::asio::steady_timer t(io,std::chrono::milliseconds(1000));
//          std::string message1 = make_daytime_string();
//          std::cout<<message1<<std::endl;
          boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
          t.wait();

      }

    }
  }
  catch (std::exception& e)
  {
    std::cerr <<e.what() << std::endl;
  }

  return 0;
}
