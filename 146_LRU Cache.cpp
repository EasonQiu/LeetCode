// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// 同时维护hashtable和list，保证他们的最大size不超过capacity
// make_pair 还有一种写法是：cache[key] = { value, used.begin() };
// 注意这里key保证不会有重复，所以list中只需保存int就行，不用保存对应的map中的iterator
// case分类的时候以key是否存在在map中为分界
class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
  	auto map_pos = map_.find(key);
  	if (map_pos != map_.end()) {
  		list_.erase(map_pos->second.second);
  		map_pos->second.second = list_.insert(list_.end(), key);
  		return map_pos->second.first;
  	} else {
  		return -1;
  	}
  }
    
  void put(int key, int value) {
  	auto map_pos = map_.find(key);
  	if (map_pos != map_.end()) {
  		list_.erase(map_pos->second.second);
  		map_pos->second.second = list_.insert(list_.end(), key);
  		map_pos->second.first = value;
  	} else {
  		if (list_.size() < capacity_) {
  			map_[key] = make_pair(value, list_.insert(list_.end(), key));
  		} else {
  			map_.erase(list_.front());
  			list_.erase(list_.begin());
  			map_[key] = make_pair(value, list_.insert(list_.end(), key));
  		}
  	}
  }

 private:
 	int capacity_;
 	list<int> list_;
 	unordered_map<int, pair<int, list<int>::iterator> > map_;
};