#include "task_queue.h"

void Task_queue::push_task(const my_task &task_func)
{
    boost::unique_lock<boost::mutex> lock(my_mutex);
    my_queue.push(task_func);
    cond.notify_one();
}

my_task Task_queue::get_task()
{
    boost::unique_lock<boost::mutex> lock(my_mutex);
    if(my_queue.size()==0)
    {
        cond.wait(lock);
    }
    my_task task(my_queue.front());
    my_queue.pop();
    return task;
}

int Task_queue::get_size()
{
    return my_queue.size();
}
