#ifndef MY_TASK_QUEUE
#define MY_TASK_QUEUE

#include <queue>
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

//定义任务
typedef boost::function<void(void)> my_task;

class Task_queue:boost::noncopyable
{
public:
    void push_task(const my_task & task_func);
    my_task get_task();
    int get_size();
private:
    std::queue<my_task> my_queue;
    boost::condition_variable_any cond;
    boost::mutex my_mutex;
};

#endif
