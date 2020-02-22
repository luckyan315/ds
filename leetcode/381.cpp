#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <random>

using namespace std;


// accept
// 88ms, 26.62%
// 24.6MB, 11.11%
class RandomizedCollection {
public:
    map<int, set<int>> _map;
    vector<int> _data;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool isExisted = _map.count(val) != 0;
        if(!isExisted) _map[val] = set<int>();

        _map[val].insert(_data.size());
        _data.push_back(val);
        return !isExisted;

    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(_map.count(val) == 0) return false;

        int idx = *_map[val].begin();
        _map[val].erase(idx);
        int lastIdx = _data.size() - 1;
        if(idx != lastIdx) {
            _data[idx] = _data[lastIdx];
            _map[_data[lastIdx]].erase(lastIdx);
            _map[_data[lastIdx]].insert(idx);
        }
        _data.pop_back();

        if(_map[val].empty()) _map.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return _data[rand() % _data.size()];
    }
};


// accept
// 124ms, 12.23%
// 24.6MB, 11.11%
class RandomizedCollection1 {
public:
    map<int, set<int>> _map;
    vector<int> _data;

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool isExist = _map.count(val) != 0;
        if (!isExist) {
            _map[val] = set<int>({});
        }

        _map[val].insert(_data.size());
        _data.push_back(val);
        return !isExist;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(_map.count(val) == 0) {
            return false;
        }

        auto iter = std::begin(_map[val]);
        advance(iter, 0);
        int idx = *iter;
        _map[val].erase(iter);

        int lastIdx = _data.size() - 1;
        if(idx != lastIdx) {
            int lastVal = _data[lastIdx];
            _data[idx] = lastVal;
            _map[lastVal].erase(lastIdx);
            _map[lastVal].insert(idx);
        }
        _data.pop_back();
        if(_map[val].empty()) _map.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return _data[rand() % _data.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char *argv[])
{
    RandomizedCollection* obj = new RandomizedCollection();
    bool param_1 = obj->insert(1);
    cout << "obj->insert(1) : " << param_1 << endl;
    bool param_2 = obj->insert(1);
    cout << "obj->insert(1) : " << param_2 << endl;
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
