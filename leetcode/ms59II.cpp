#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

using namespace std;

// accept
// 212ms, beats 26.77%
// 51.3MB, 100.00%
class MaxQueue {
public:
    deque<int> dq;
    queue<int> q;
    MaxQueue() {

    }

    int max_value() {
        if(dq.empty()) return -1;
        return dq.front();
    }

    void push_back(int value) {
        while(!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if(q.empty()) return -1;
        int f = q.front();
        if(f == dq.front()) dq.pop_front();
        q.pop();
        return f;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(int argc, char *argv[])
{
    MaxQueue* obj = new MaxQueue();
    cout << obj->max_value() << endl;
    obj->push_back(1);
    obj->push_back(2);
    cout << "after push 2: max: " << obj->max_value() << endl;
    obj->push_back(0);
    cout << "after push 0: max: " << obj->max_value() << endl;
    obj->push_back(3);
    cout << "after push 3: max: " << obj->max_value() << endl;
    obj->pop_front();
    cout << "after pop front: max: " << obj->max_value() << endl;

    return 0;
}
