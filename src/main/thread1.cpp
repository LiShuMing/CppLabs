#include <vector>
#include <iostream>
#include <thread>
#include <cassert>
#include <atomic>
#include <cstring>

 
std::atomic<int> cnt = {0};
 
void f()
{
    for (int n = 0; n < 1000; ++n) {
        cnt.fetch_add(1, std::memory_order_relaxed);
    }
}
 
void test1()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f);
    }
    for (auto& t : v) {
        t.join();
    }
    std::cout << "Final counter value is " << cnt << '\n';
}

std::atomic<bool> ready{ false };
int data = 0;
void producer()
{
    data = 100;                                       // A
    ready.store(true, std::memory_order_release);     // B
}
void consumer()
{
    while (!ready.load(std::memory_order_acquire))    // C
        ;
    assert(data == 100); // never failed              // D
}

void test2() {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}


int a; int b; int c;
void thread1() {
  a = 1;
  b = a + 2;
  c = a + 3;
}

void thread2() {
  std::cout << "a="<<a<<" b="<<b<<" c="<<c<<std::endl;
}

void test3() {
  std::thread t1(thread1);
  std::thread t2(thread2);
  t1.join();
  t2.join();
}

void test4() {
  int ret = std::strcmp("a ", "a    ");
  std::cout<<"ret :"<<ret<<std::endl;
}

int main() {
  //test1();
  //test2();
  //test3();
  test4();
}
