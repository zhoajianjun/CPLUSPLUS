/*#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/strand.hpp>
#include <chrono>
#include <thread>
#include <iostream>
using namespace boost::asio;
void printMessage1( const boost::system::error_code &  e  ) {
    for( int i = 0; i < 5; ++i ) {
        std::cout << "message from timer1." << std::endl;
    }
}
void printMessage2( const boost::system::error_code &  e  ) {
    for( int i = 0; i < 5; ++i ) {
        std::cout << "message from timer2." << std::endl;
    }
}
int main()
{
    io_service ioservice;
    strand s{ ioservice };
    steady_timer timer1{ ioservice, std::chrono::seconds{ 1 } };
    timer1.async_wait( s.wrap( printMessage1 ) );

    steady_timer timer2{ ioservice, std::chrono::seconds{ 1 } };
    timer1.async_wait( s.wrap( printMessage2 ) );
    std::thread thread1{ [&ioservice](){ ioservice.run(); } };
    std::thread thread2{ [&ioservice](){ ioservice.run(); } };
    thread1.join();
    thread2.join();
    return 0;
}
*/

#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>
using namespace boost::asio;
using namespace boost::asio::ip;
io_service ioservice;
tcp::resolver resolver{ ioservice };
tcp::socket tcp_socket{ ioservice };
std::array<char, 4096> bytes;
// 当客户端读取到服务器传来的部分数据时，将调用 read_handler()
void read_handler( const boost::system::error_code &ec, std::size_t bytes_transferred ) {
    if( !ec ) {
        std::cout.write( bytes.data(), bytes_transferred );            // 向控制台写入读取到的数据
        tcp_socket.async_read_some( buffer( bytes ), read_handler );   // 继续读取剩下的数据
    }
}
// 当与服务器建立连接之后，将调用 connect_handler()
void connect_handler( const boost::system::error_code &ec ) {
    if( !ec ) {
        std::string request = "GET / HTTP/1.1\r\nHost: www.baidu.com\r\n\r\n";
        write( tcp_socket, buffer( request ) );                           // 向服务端发出请求
        tcp_socket.async_read_some( buffer( bytes ), read_handler );      // 读取服务器传来的部分数据
    }
}
// 当域名解析结束时，将调用 resolve_handler()
void resolve_handler( const boost::system::error_code &ec, tcp::resolver::iterator it ) {
   if( !ec ) {
       tcp_socket.async_connect( *it, connect_handler );    // 与服务器建立连接
   }
}
int main()
{
    tcp::resolver::query query{ "www.baidu.com", "80" };
    resolver.async_resolve( query, resolve_handler );    // 域名解析
    ioservice.run();
    return 0;
}
