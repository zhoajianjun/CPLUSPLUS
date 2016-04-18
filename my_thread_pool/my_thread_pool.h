#ifndef MY_THREAD_POOL
#define MY_THREAD_POOL
#include "task_queue.h"
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>


typedef boost::function<void(void)> my_task;

class My_thread_pool:boost::noncopyable
{
public:
    My_thread_pool(int num);
    ~My_thread_pool();
    void init();

    void stop();

    void  post(const my_task & task);

    void wait();

private:
    Task_queue my_queue;
    boost::thread_group my_thread_group;
    int thread_num;
    volatile bool is_run;
    void run();
};

#endif
