#include "my_thread_pool.h"


My_thread_pool::My_thread_pool(int num):thread_num(num),is_run(false){}

My_thread_pool::~My_thread_pool(){}

void My_thread_pool::init()
{
    is_run=true;
    if(thread_num<=0)
        return;
    for(int i=0;i<thread_num;++i)
    {
        my_thread_group.add_thread(new boost::thread(boost::bind(&My_thread_pool::run,this)));
    }
}

void My_thread_pool::stop()
{
    is_run=false;
}

void My_thread_pool::post(const my_task &task)
{
    my_queue.push_task(task);
}

void My_thread_pool::wait()
{
    my_thread_group.join_all();
}

void My_thread_pool::run()
{
    while(is_run)
    {

        my_task task=my_queue.get_task();
        task();
    }
}
