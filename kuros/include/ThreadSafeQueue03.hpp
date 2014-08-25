#ifndef THREADSAFEQUEUE03_HPP
#define THREADSAFEQUEUE03_HPP


//#include <mutex>
//#include <condition_variable>
//#include <memory>
#include <queue>

#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>

#include <iostream>

using std::cout;
using std::endl;

/*

Based on C++ Concurrency in Action but
with accept, reject and reset added.

Rewritten for c++03 with boost.

*/


template<typename T>

class ThreadSafeQueue03

{

private:

    //mutable std::mutex mut;
    mutable boost::mutex mut;

    std::queue<T> data_queue;

    //std::condition_variable data_cond;
    boost::condition_variable data_cond;

    bool canAccept;

public:

    ThreadSafeQueue03() : canAccept(true)

    {}

    ThreadSafeQueue03(ThreadSafeQueue03 const& other) : canAccept(true)

    {

        //std::lock_guard<std::mutex> lk(other.mut);
        boost::lock_guard<boost::mutex> lk(other.mut);

        data_queue=other.data_queue;

    }



    void push(T new_value)

    {

        //std::lock_guard<std::mutex> lk(mut);
        boost::lock_guard<boost::mutex> lk(mut);

        if (canAccept)
        {
            data_queue.push(new_value);
            data_cond.notify_one();
        }
    }


    /**
    Only touches value reference if queue
    is accepting.
    */
    void wait_and_pop(T& value)

    {
//        std::unique_lock<std::mutex> lk(mut);
//        data_cond.wait(lk,[this] {return !data_queue.empty() || !canAccept;});

        boost::unique_lock<boost::mutex> lk(mut);

        while(data_queue.empty() && canAccept)
        {
            data_cond.wait(lk);
        }

        if (canAccept)
        {
            value=data_queue.front();
            data_queue.pop();
        }

    }



//    std::shared_ptr<T> wait_and_pop()
//
//    {
//        std::unique_lock<std::mutex> lk(mut);
//
//        data_cond.wait(lk,[this] {return !data_queue.empty() || !canAccept;});
//
//        if (canAccept)
//        {
//            std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
//            data_queue.pop();
//            return res;
//        }
//        else
//        {
//            return std::shared_ptr<T>();
//        }
//    }



//    bool try_pop(T& value)
//
//    {
//
//        std::lock_guard<std::mutex> lk(mut);
//
//        if(data_queue.empty() || !canAccept)
//        {
//            return false;
//        }
//
//        value=data_queue.front();
//
//        data_queue.pop();
//
//    }



//    std::shared_ptr<T> try_pop()
//
//    {
//
//        std::lock_guard<std::mutex> lk(mut);
//
//        if(data_queue.empty() || !canAccept)
//        {
//            return std::shared_ptr<T>();    // return empty shared_ptr on failure
//        }
//
//        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
//
//        data_queue.pop();
//
//        return res;
//
//    }



    bool empty() const

    {

        boost::lock_guard<boost::mutex> lk(mut);

        return data_queue.empty();

    }

    bool accepting() const

    {
        boost::lock_guard<boost::mutex> lk(mut);

        return canAccept;

    }

    /**
    Empties queue and sets to nonaccepting.
    */
    void reject()
    {
        //cout << "ThreadSafeQueue03 rejecting." << endl;
        {
            boost::lock_guard<boost::mutex> lk(mut);
            while(!data_queue.empty())
            {
                data_queue.pop();
            }
            canAccept = false;
        }
        //cout << "ThreadSafeQueue03 notifying." << endl;
        data_cond.notify_all();
    }

    void accept()
    {
        {
            boost::lock_guard<boost::mutex> lk(mut);
            canAccept = true;
        }
        data_cond.notify_all();
    }

    void reset()
    {
        {
            boost::lock_guard<boost::mutex> lk(mut);

            while(!data_queue.empty())
            {
                data_queue.pop();
            }

            canAccept = true;
        }
        data_cond.notify_all(); // TODO: are all of those notifys necessary?
    }

};


#endif // THREADSAFEQUEUE03_HPP
