
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <functional>
#include <chrono>
#include <iostream>
#include <thread>
#include <boost/chrono.hpp>

using namespace boost::asio;
class printer
{
public:
    printer( boost::asio::io_service &service )
        : timer( service, std::chrono::seconds( 1 ) ) {
        timer.async_wait( std::bind( &printer::print_message, this ) );
    }
    void print_message() {
        if( count < 5 ) {
            std::cout << count << std::endl;
            ++count;
            // 设定定时器下一秒触发
            timer.expires_at( timer.expires_at() + std::chrono::seconds( 1 ) );
            // 异步地等待定时器触发
            timer.async_wait( std::bind( &printer::print_message, this ) );
        }
    }
private:
    boost::asio::steady_timer timer;
    int count = 0;
};
int main1()
{
    io_service ioservice;
    printer p( ioservice );

    ioservice.run();

    return 0;
}

int main2()
{
    io_service ioserver;
    steady_timer timer1{ioserver,std::chrono::seconds(1)};
    timer1.async_wait([](const boost::system::error_code& e){
        for (int i=0;i<5;++i) {
            std::cout<<"message thread1"<<std::endl;
        }
    });
    steady_timer timer2{ioserver,std::chrono::seconds(1)};
    timer2.async_wait([](const boost::system::error_code& e){
        for (int i=0;i<5;++i) {
            std::cout<<"message thread2"<<std::endl;
        }
    });

    std::thread thread1{ [&ioserver](){ ioserver.run(); } };
    std::thread thread2{ [&ioserver](){ ioserver.run(); } };
    thread1.join();
    thread2.join();

}
int main3()
{
    io_service io;
    steady_timer t(io,std::chrono::milliseconds(5000));

    t.wait();
    std::cout<<"hello asio"<<std::endl;


}
using namespace std;
int main()
{
    io_service io;
    steady_timer t(io,std::chrono::milliseconds(5000));
    t.async_wait([](const boost::system::error_code &e){
        cout<<"hello asio"<<endl;

    });
    io.run();

    cout<<"hello boost"<<endl;



}

