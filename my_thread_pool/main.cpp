
#include "my_thread_pool.h"
#include <iostream>

typedef boost::function<void(void)> my_task;


void print1(int i)
{
std::cout<<"task:"<<i<<std::endl;
}

int main()
{
    My_thread_pool tp(4);
    tp.init();

    my_task t[4];
    for (int i= 0; i<4;++i)
    {
        t[i]=boost::bind(print1,i+1);
        tp.post(t[i]);
    }

    tp.wait();
    return 0;
}


