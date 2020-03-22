#include <iostream>
#include <deque>

using namespace std;

class CustomStack {
public:
    int maxLength = 0;
    deque<int> que;
    CustomStack(int maxSize) {
        maxLength = maxSize;
    }

    void push(int x) {
        if(que.size() == maxLength) return;

        que.push_back(x);
    }

    int pop() {
        if(que.empty()) return -1;
        int e = que.back();
        que.pop_back();
        return e;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < que.size(); ++i) {
            que[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
