#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


using namespace std;

#define N_THREAD 1000

//atomic<int> a{0};
int a{0};

void thread_f1() {
    for (int i = 0; i < 10; i++) {
        a++;
    }
    //std::this_thread::sleep_for(10ms);
}

int main() {
    /**
	for (int i=0; i < 100; i++) {
		cout<<"i:"<<i<<", popcount:"<<__builtin_popcount(i)<<endl;
	}*/

    vector<thread> ts(N_THREAD);
    for (int i=0; i<N_THREAD; i++) {
        //ts.emplace_back(std::thread(thread_f1));
        ts[i] = std::thread(thread_f1);
    }
    for (int i=0; i<N_THREAD; i++) {
        ts[i].join();
    }
    //cout<<"final sum:"<<a.load()<<endl;
    cout<<"final sum:"<<a<<endl;
	return 0;
}
