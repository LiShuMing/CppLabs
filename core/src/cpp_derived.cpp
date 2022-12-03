
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <set>
#include <thread>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>

#include <immintrin.h>
#include <x86intrin.h>

using namespace std;
//A是一个父类 , 析构函数不是虚函数
class A
{
public:
	 A()
	{
		cout << " A constructor" << endl;
	}
	  virtual ~A()
	{
		cout << " A destructor" << endl;
	}
};

//B是A的子类
class B : public A
{
public:
	B()
	{
		cout << " B constructor" << endl;
	} 
	~B() override
	{
		cout << " B destructor" << endl;
	}
};

int main() {
  A* a = new A();
  delete a;
  B* b = new B();
  delete b;
  A* b2 = new B();
delete b2;
}
