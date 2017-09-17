// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LFUCache cache = new LFUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4


// LRU想法差不多，一个map是稍作改进的key value对但多存一些frequency和itr
// 用一个freq，list of keys的hashmap来统计频率，同时用一个min_freq指向当前最小freq用来pop
// 注意Corner case如cap小于等于0
// 不知道为什么map[key] = Node();无法插入
struct Node {
    int value;
    int freq;
    list<int>::iterator itr;
    Node(int v, int f, list<int>::iterator i) : value(v), freq(f), itr(i) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        min_freq = INT_MAX;
    }
    
    int get(int key) {
        auto pos = map.find(key);
        if (pos != map.end()) {
            frequent[pos->second.freq].erase(pos->second.itr);
            frequent[++pos->second.freq].push_back(key);
            pos->second.itr = --frequent[pos->second.freq].end();
            if (frequent[min_freq].empty())  ++min_freq;
            return pos->second.value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cap <= 0)  return; // corner case
        auto pos = map.find(key);
        if (pos != map.end()) {
            pos->second.value = value;
            frequent[pos->second.freq].erase(pos->second.itr);
            frequent[++pos->second.freq].push_back(key);
            pos->second.itr = --frequent[pos->second.freq].end();
            if (frequent[min_freq].empty())  ++min_freq;
        } else {
            if (map.size() >= cap) {
                int key = frequent[min_freq].front();
                frequent[min_freq].pop_front();
                map.erase(key);
            }
            frequent[1].push_back(key);
            // map[key] = Node(value, 1, --frequent[1].end());
            map.insert(make_pair(key, Node(value, 1, --frequent[1].end())));
            min_freq = 1;
        }
    }
    
private:
    unordered_map<int, Node> map; // <key, {value, freqency, list_itr}>
    unordered_map<int, list<int> > frequent; // <freqency, list of keys>
    int cap;
    int min_freq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */