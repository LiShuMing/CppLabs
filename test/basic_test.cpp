#include <gtest/gtest.h>

#include <atomic>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "foo.h"

using namespace std;

namespace test {

struct X {
    int x_;
    X() { std::cout << "default constructor\n"; }
    X(int x) {
        x_ = x;
        std::cout << "default constructor:" << x << std::endl;
    }

    X(const X&) { std::cout << "copy constructor\n"; }

    ~X() { std::cout << "deconstructor:" << x_ << std::endl; }

    void print() { cout << " print :" << x_ << endl; }
};

struct A1 {
    A1() { printf("A1 ctror"); }
    virtual ~A1() { printf("A1 dtor\n"); }
};
struct A2 : A1 {
    virtual ~A2() { printf("A2 dtor\n"); }
};
struct A3 : A2 {
    virtual ~A3() { printf("A3 dtor\n"); }
};

struct B1 {
    B1() { printf("B1 ctor\n"); }
    B1(const B1& b) { printf("B1 copy\n"); }
    ~B1() { printf("B1 dtor\n"); }
};
struct B2 : B1 {
    B2() { printf("B2 ctro\n"); }
    B2(const B2& b) { printf("B2 copy\n"); }
    ~B2() { printf("B2 dtor\n"); }
};
struct B3 : B2 {
    B3() { printf("B3 ctror\n"); }
    B3(const B3& b) { printf("B3 copy\n"); }
    ~B3() { printf("B3 dtor\n"); }
};

struct StructRef {
    const B1& b1;
    const B2& b2;
    int a {1};
};

struct StructNonRef {
    B1 b1;
    B2 b2;
    int a {1};
};


// Basic Test
class BasicTest : public testing::Test {};

TEST_F(BasicTest, assertion) {
    ASSERT_EQ(1, 1);
    ASSERT_TRUE(true);
    GTEST_LOG_(INFO) << "ok";
}

TEST_F(BasicTest, foobar) {
    ASSERT_EQ(add(1, 2), 3);
    GTEST_LOG_(INFO) << "1+2=" << add(1, 2);
}

TEST_F(BasicTest, atomic) {
    std::atomic<void*> a(nullptr);
    void* b = a;
    a.compare_exchange_strong(b, (void*)20);
}

TEST_F(BasicTest, test1) {
    std::map<int, X> numbers = {{1, X()}, {2, X()}, {3, X()}};
    std::cout << "STARTING LOOP 1\n";
    for (const std::pair<int, X>& p : numbers) {
    }
    std::cout << "ENDING LOOP 1 \n";

    std::cout << "STARTING LOOP 2\n";
    for (auto&& p : numbers) {
    }
    std::cout << "ENDING LOOP 2 \n";

    std::cout << "STARTING LOOP 3\n";
    for (auto& it : numbers) {
        // std::cout<<"it:"<<it.first<<", "<<it.second;
        std::cout << "it:" << it.first << std::endl;
    }
    std::cout << "ENDING LOOP 3 \n";
}

TEST_F(BasicTest, test2) {
    X x;
    X x1(1);
    x1.print();
    auto func = [&x]() { x.print(); };
    func();
}

TEST_F(BasicTest, test3) {
    A1* a = new A3;
    delete a;
    printf("\n");

    B1* b = new B3;
    delete b;
    printf("\n");

    B3* b2 = new B3;
    delete b2;
}

TEST_F(BasicTest, test4) {
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

TEST_F(BasicTest, TestQueue) {
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 10; i > 0; i--) {
        que.push(i);
    }
    int sz = que.size();
    while (!que.empty()) {
        int val = que.top();
        cout << "val:" << val << endl;
        que.pop();
    }
    vector<int> va;
    va.push_back(1);
    va.clear();
    va.clear();
}

TEST_F(BasicTest, TestStructRef) {
    {
        cout << "start ref" << endl;
        B1 b1;
        B2 b2;
        printf("struct ref\n");
        StructRef ref{.b1 = b1, .b2 = b2};
    }
    {
        cout << "start non ref" << endl;
        B1 b1;
        B2 b2;
        printf("struct non ref\n");
        StructNonRef nonref{.b1 = b1, .b2 = b2};
    }
}

TEST_F(BasicTest, TestString1) {
    int ret = std::strcmp("a ", "a    ");
    std::cout << "ret :" << ret << std::endl;
    ASSERT_EQ(ret, -1);
}

} // namespace test

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
