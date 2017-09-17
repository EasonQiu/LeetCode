#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void SelectionSort(vector<int> &nums) {
    int target;
    for (int i = 0; i < nums.size(); ++i) {
        target = i;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[target] > nums[j])  target = j;
        }
        swap(nums[target], nums[i]);
    }
}

void BubbleSort(vector<int> &nums) {
    if (nums.size() <= 1)  return;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size()-i; ++j) {
            if (nums[j+1] < nums[j]) {
                swap(nums[j+1],nums[j]);
            }
        }
    }
}

void InsertSort(vector<int> &nums) {
    if (nums.size() <= 1)  return;
    int tmp;
    for (int i = 1; i < nums.size(); ++i) {
        // find the position to insert
        int j;
        for (j = 0; j < i; ++j) {
            if (nums[j] >= nums[i])  break;
        }
        // move the numbers
        tmp = nums[i];
        for (int k = i; k >= j+1; --k) {
            nums[k] = nums[k-1];
        }
        nums[j] = tmp;
    }
}


int partition2(vector<int> &nums, int left, int right) {
    int pivot = nums[right];
    int first = left, second = right - 1;
    while (first <= second) {
        while (first <= second && nums[first] <= pivot)  ++first;
        while (first <= second && nums[second] > pivot)  --second;
        if (first < second)  swap(nums[first++], nums[second--]);
    }
    swap(nums[first], nums[right]);
    return first;
}
// 快速排序
int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j <= right - 1; ++j) {
        if (nums[j] <= pivot)  swap(nums[i++], nums[j]);
    }
    swap(nums[i], nums[right]);
    return i;
}
// driver function
void QuickSort(vector<int> &nums, int left, int right) {
    if (left >= right)  return;
    int pos = partition(nums, left, right);
    QuickSort(nums, left,  pos - 1);
    QuickSort(nums, pos + 1, right);
}

// 归并排序
void Merge(vector<int> &nums,vector<int> &temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];
    }
    while (i <= mid)    temp[k++] = nums[i++];
    while (j <= right)  temp[k++] = nums[j++];
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}
// driver function
void MergeSort(vector<int> &nums,vector<int> &temp, int left, int right) {
    if (left >= right)  return;
    int mid = left + (right - left) / 2;
    MergeSort(nums, temp, left, mid);
    MergeSort(nums, temp, mid + 1, right);
    Merge(nums, temp, left, mid, right);
}

void BucketSort(vector<int> &nums) {
    // assume all numbers are less than 100
    vector<priority_queue<int, vector<int>, greater<int>> > bucket(10);
    for (int i = 0; i < nums.size(); ++i) {
        bucket[nums[i] / 10].push(nums[i]);
    }
    nums.clear();
    for (int i = 0; i < 10; ++i) {
        while (bucket[i].size() != 0) {
            int val = bucket[i].top();
            bucket[i].pop();
            nums.push_back(val);
        }
    }
}

int main() {
    vector<int> nums = {63,55,37,34,28,59,52,16}, temp(nums.size());
//    SelectionSort(nums);
//    BubbleSort(nums);
//    InsertSort(nums);
   QuickSort(nums, 0, nums.size()-1);
   // MergeSort(nums, temp, 0, nums.size()-1);
    // BucketSort(nums);
    
    for (int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    return 0;
}

// ================================================================

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt = 0;
        vector<int>& pair = pairs[0];
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0 || pairs[i][0] > pair[1]) {
                pair = pairs[i];
                cnt++;
            }
        }
        return cnt;
    }

private:
    static bool cmp(vector<int>& a, vector<int>&b) { // comparator 写法
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }
};