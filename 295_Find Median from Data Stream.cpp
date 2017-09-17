#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        stream.insert(num);
        if (stream.size() > 1) {
            if (stream.size() % 2 == 0) {
                if (num >= *mid)  ++mid;
            } else {
                if (num < *mid)  --mid;
            }
        } else {
            mid = stream.begin();
        }
    }
    
    double findMedian() {
        if (stream.size() % 2 == 0) {
            return (double(*mid) + *prev(mid, 1)) / 2;
        } else {
            return double(*mid);
        }
    }
    
private:
    multiset<int> stream;
    multiset<int>::iterator mid;
};

// 总共就四种情况，两个heap的size是否相等，num是否大于max_heap.top()
class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}
    
  void addNum(int num) {
    if (max_heap.size() == min_heap.size()) {
      max_heap.push(num);
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else {
      min_heap.push(num);
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
  	if (max_heap.size() == min_heap.size()) {
  		return (max_heap.top() + min_heap.top()) / 2.0;
  	} else {
  		return min_heap.top();
  	}
  }

 private:
 	priority_queue<int, vector<int>, less<int> > max_heap;     // smaller
 	priority_queue<int, vector<int>, greater<int> > min_heap;  // larger
};

int main() {
	MedianFinder obj;
	obj.addNum(1);  obj.addNum(2);
	cout << obj.findMedian() << endl;
	obj.addNum(3);
	cout << obj.findMedian() << endl;

	return 0;
}