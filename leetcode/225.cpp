#include <iostream>
#include <deque>

using namespace std;

// accept
// 4ms, beats 66.56%
// 9.5MB, beats 5.18%
class MyStack {
public:
    deque<int> que;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = que.back();
        que.pop_back();
        return n;
    }

    /** Get the top element. */
    int top() {
        return que.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char *argv[])
{

    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(15);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;

    return 0;
}
