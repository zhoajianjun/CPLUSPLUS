#include <boost/thread/thread.hpp>
#include <boost/thread/once.hpp>
#include <cassert>
#include <iostream>
using namespace std;

int value=0;
boost::once_flag once = BOOST_ONCE_INIT;

void init()
{
    ++value;
    cout<<value<<endl;
}

void thread_proc()
{
    boost::call_once(&init, once);
}

int main(int argc, char* argv[])
{
    boost::thread_group threads;
    for (int i=0; i<5; ++i)
        threads.create_thread(&thread_proc);
    threads.join_all();
    //assert(value == 1);
}
