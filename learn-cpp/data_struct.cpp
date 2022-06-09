#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


using namespace std;

#define N_THREAD 1000

// https://stackoverflow.com/questions/63584337/do-i-need-an-atomic-if-a-value-is-only-written
//
// According to §5.1.2.4 ¶25 and ¶4 of the ISO C11 standard, two different threads writing to the same memory location
// using non-atomic operations in an unordered fashion causes undefined behavior. The ISO C standard makes no exception
// to this rule if all threads are writing the same value.
//

//atomic<int> a{0};
int a{0};

void thread_f1() {
    for (int i = 0; i < 10; i++) {
        a++;
    }
    //std::this_thread::sleep_for(10ms);
}

void test_multi_threads_1() {
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
}

int tab[5];
bool test_undefined_behavior_1(int v) {
    for (int i = 0; i  <= 5; i++) {
        if (tab[i] == v) return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 10; i++) {
        cout<<"test_undefined_behavior_1 i:"<<i<<", ans:"<<(test_undefined_behavior_1(i) ? "true" : "false")<<endl;
    }
}
