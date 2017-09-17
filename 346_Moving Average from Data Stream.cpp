// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3


class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_size = size;
    }
    
    double next(int val) {
        if (nums.size() == max_size) {
            sum -= nums.front();
            nums.pop();
        }
        sum += val;
        nums.push(val);
        return sum / (double)nums.size();
    }
    
private:
    int max_size;
    int sum = 0;
    queue<int> nums;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */