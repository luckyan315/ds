#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>

using namespace std;

// accept
// 232ms, beats 15.83%
// 40MB, beats 40.00%
class LFUCache {
    struct Node {
        int key;
        int value;
        int freq;
        Node(int _key, int _val, int _freq): key(_key), value(_val), freq(_freq){}
    };
public:
    unordered_map<int, list<Node>::iterator> ktb; // key table
    unordered_map<int, list<Node>> ftb; // freq table
    int capacity;
    int minFreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        ktb.clear();
        ftb.clear();
    }

    int get(int key) {
        if(capacity == 0) return -1;
        auto it = ktb.find(key);
        if(it == ktb.end()) return -1;

        auto node = it->second;
        int value = node->value;
        int freq = node->freq;
        ftb[freq].erase(node);

        if(ftb[freq].size() == 0) {
            ftb.erase(freq);
            if(freq == minFreq) {
                minFreq++;
            }
        }

        ftb[freq+1].push_front(Node(key, value, freq + 1));
        ktb[key] = ftb[freq+1].begin();
        return value;
    }

    void put(int key, int value) {
        if(capacity == 0) return;

        auto kit = ktb.find(key);
        if(kit == ktb.end()) {
            if(ktb.size() == capacity) {
                Node& n = ftb[minFreq].back();
                ktb.erase(n.key);
                ftb[minFreq].pop_back();
                if(ftb[minFreq].size() == 0) {
                    ftb.erase(minFreq);
                }
            }
            ftb[1].push_front(Node(key, value, 1));
            ktb[key] = ftb[1].begin();
            minFreq = 1;
        } else {
            auto node = kit->second;
            int freq = node->freq;
            ftb[freq].erase(node);
            if(ftb[freq].size() == 0) {
                ftb.erase(freq);
                if(freq == minFreq) minFreq++;
            }
            ftb[freq + 1].push_front(Node(key, value, freq + 1));
            ktb[key] = ftb[freq + 1].begin();
        }
    }
};



// copy right https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/
// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};

class LFUCachexx {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCachexx(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};


/**
 * your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[])
{
    LFUCache cache = LFUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回 1
    cache.put(3, 3);    // 去除 key 2
    cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
    cout << cache.get(3) << endl;       // 返回 3
    cache.put(4, 4);    // 去除 key 1
    cout << cache.get(1) << endl;       // 返回 -1 (未找到 key 1)
    cout << cache.get(3) << endl;       // 返回 3
    cout << cache.get(4) << endl;       // 返回 4

    return 0;
}
