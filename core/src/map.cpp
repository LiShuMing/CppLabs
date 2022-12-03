#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct X
{
    int x_;
    X()
    {
        std::cout << "default constructor\n";
    }
    X(int x) {
        x_ = x;
        std::cout << "default constructor:" << x << std::endl;
    }

    X(const X&)
    {
        std::cout << "copy constructor\n";
    }

   ~X() {
        std::cout << "deconstructor:" << x_ << std::endl;
    }

   void print() {
       cout << " print :" << x_ << endl;
   }
};

void testX() {
   X x;
}

void test1()
{
    std::map<int, X> numbers = {{1, X()}, {2, X()}, {3, X()}};
    std::cout << "STARTING LOOP 1\n";
    for (const std::pair<int, X>& p : numbers)
    {
    }
    std::cout << "ENDING LOOP 1 \n";

    std::cout << "STARTING LOOP 2\n";
    for (auto&& p : numbers)
    {
    }
    std::cout << "ENDING LOOP 2 \n";

    std::cout << "STARTING LOOP 3\n";
    for (auto& it : numbers) {
        //std::cout<<"it:"<<it.first<<", "<<it.second;
        std::cout<<"it:"<<it.first<<std::endl;
    }
    std::cout << "ENDING LOOP 3 \n";

}

void test2() {
    X x;
    X x1(1);
    x1.print();
    auto func = [&x]() {
        x.print();
    };
    func();
}

struct A1      { virtual ~A1() { printf("A1 dtor\n"); } };
struct A2 : A1 { virtual ~A2() { printf("A2 dtor\n"); } };
struct A3 : A2 { virtual ~A3() { printf("A3 dtor\n"); } };

struct B1      { ~B1() { printf("B1 dtor\n"); } };
struct B2 : B1 { ~B2() { printf("B2 dtor\n"); } };
struct B3 : B2 { ~B3() { printf("B3 dtor\n"); } };

void test3() {
   A1 * a = new A3;
   delete a;
   printf("\n");

   B1 * b = new B3;
   delete b;
   printf("\n");

   B3 * b2 = new B3;
   delete b2;
}

void test4() {
	
    std::vector<int> alice{1, 2, 3};
    std::vector<int> bob{7, 8, 9, 10};
    std::vector<int> eve{1, 2, 3};
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}

int main() {
  // test1();
  //testX();
  //test2();
  //test3();
  test4();
}
