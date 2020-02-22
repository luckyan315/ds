#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <random>

using namespace std;

// accept
// 44ms, 98.21%
// 22.5MB, 6.39%
class RandomizedSet {
public:
    map<int, int> _map;
    vector<int> _data;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(_map.count(val) != 0) return false;

        _map[val] = _data.size();
        _data.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(_map.count(val) == 0) return false;

        int idx = _map[val];
        int lastIdx = _data.size() - 1;
        if(idx != lastIdx) {
            _data[idx] = _data[lastIdx];
            _map[_data[lastIdx]] = idx;
        }

        _data.pop_back();
        _map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return _data[rand() % _data.size()];
    }
};

int main(int argc, char *argv[])
{
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    cout << "obj->insert(1) : " << param_1 << endl;
    bool param_2 = obj->remove(1);
    cout << "obj->remove(1) : " << param_2 << endl;
    bool param_3 = obj->insert(2);
    cout << "obj->insert(2) : " << param_3 << endl;
    int param_4 = obj->getRandom();
    cout << "obj->random() : " << param_4 << endl;
    bool param_5 = obj->remove(1);
    cout << "obj->remove(1) : " << param_5 << endl;
    int param_6 = obj->getRandom();
    cout << "obj->getRandom() : " << param_6 << endl;

    return 0;
}
