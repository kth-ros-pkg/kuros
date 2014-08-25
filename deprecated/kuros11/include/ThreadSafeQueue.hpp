#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

#include <iostream>

using std::cout;
using std::endl;

/*

Based on C++ Concurrency in Action but
with accept, reject and reset added.

*/


template<typename T>

class ThreadSafeQueue

{

private:

    mutable std::mutex mut;

    std::queue<T> data_queue;

    std::condition_variable data_cond;

    bool canAccept = true;

public:

    ThreadSafeQueue()

    {}

    ThreadSafeQueue(ThreadSafeQueue const& other)

    {

        std::lock_guard<std::mutex> lk(other.mut);

        data_queue=other.data_queue;

    }



    void push(T new_value)

    {

        std::lock_guard<std::mutex> lk(mut);

        if (canAccept)
        {
            data_queue.push(new_value);
            data_cond.notify_one();
        }
    }



    void wait_and_pop(T& value)

    {

        std::unique_lock<std::mutex> lk(mut);

        data_cond.wait(lk,[this] {return !data_queue.empty() || !canAccept;});

        if (canAccept)
        {
            value=data_queue.front();
            data_queue.pop();
        }
//        else
//        {
//            cout << "ThreadsafeQueue not accepting." << endl;
//        }

    }



    std::shared_ptr<T> wait_and_pop()

    {
        std::unique_lock<std::mutex> lk(mut);

        data_cond.wait(lk,[this] {return !data_queue.empty() || !canAccept;});

        if (canAccept)
        {
            std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
            data_queue.pop();
            return res;
        }
        else
        {
            return std::shared_ptr<T>();
        }
    }



    bool try_pop(T& value)

    {

        std::lock_guard<std::mutex> lk(mut);

        if(data_queue.empty() || !canAccept)
        {
            return false;
        }

        value=data_queue.front();

        data_queue.pop();

    }



    std::shared_ptr<T> try_pop()

    {

        std::lock_guard<std::mutex> lk(mut);

        if(data_queue.empty() || !canAccept)
        {
            return std::shared_ptr<T>();    // return empty shared_ptr on failure
        }

        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));

        data_queue.pop();

        return res;

    }



    bool empty() const

    {

        std::lock_guard<std::mutex> lk(mut);

        return data_queue.empty();

    }

    bool accepting() const

    {
        std::lock_guard<std::mutex> lk(mut);

        return canAccept;

    }

    void reject()
    {
        //cout << "ThreadSafeQueue rejecting." << endl;
        {
            std::lock_guard<std::mutex> lk(mut);
            while(!data_queue.empty())
            {
                data_queue.pop();
            }
            canAccept = false;
        }
        //cout << "ThreadSafeQueue notifying." << endl;
        data_cond.notify_all();
    }

    void accept()
    {
        {
            std::lock_guard<std::mutex> lk(mut);
            canAccept = true;
        }
        data_cond.notify_all();
    }

    void reset()
    {
        {
            std::lock_guard<std::mutex> lk(mut);

            while(!data_queue.empty())
            {
                data_queue.pop();
            }

            canAccept = true;
        }
        data_cond.notify_all(); // TODO: are all of those notifys necessary?
    }

};


#endif // THREADSAFEQUEUE_H
