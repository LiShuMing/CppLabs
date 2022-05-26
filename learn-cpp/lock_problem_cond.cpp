
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker() {
    cout<<"thread:"<<this_thread::get_id()<<", start to work..."<<endl;

    unique_lock<mutex> lk(m);
    cv.wait(lk, [] {return ready;});
    cout<<"thread:"<<this_thread::get_id()<<", wait done..."<<endl;
    // data += "thread:"+ to_string(this_thread::get_id()) +" after processed.";
    data += "thread after processed.";
    processed=true;
    lk.unlock();
    cv.notify_one();
}

int main() {
    thread t1(worker);
    data += "berfore start ...";
    {
        lock_guard<mutex> lk(m);
        ready=true;
    }
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    cout<<"wait 2s..."<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<"wait 2s done..."<<endl;

    cv.notify_one();
    t1.join();
}
