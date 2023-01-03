#include<queue>
#include<iostream>
#include<vector>
#include <functional>

using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 10; i > 0; i--) {
        que.push(i);
    }
    int sz = que.size();
    while (!que.empty()) {
        int val = que.top();
        cout<<"val:"<<val<<endl;
        que.pop();
    }
    vector<int> va;
    va.push_back(1);
    va.clear();
    va.clear();
}

