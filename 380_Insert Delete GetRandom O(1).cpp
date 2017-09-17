// Design a data structure that supports all following operations in average O(1) time.

// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end())  return false;
        vec.push_back(val);
        map[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // move the last number to the removed position
    bool remove(int val) {
        auto pos = map.find(val);
        if (pos == map.end())  return false;
        vec[pos->second] = vec.back();
        map[vec.back()] = pos->second;
        vec.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
    
private:
    unordered_map<int, int> map; // <val, index in vec>
    vector<int> vec; // val
};