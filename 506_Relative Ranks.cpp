// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
// For the left two athletes, you just need to output their relative ranks according to their scores.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty())  return vector<string>();
        int size = nums.size();
        scores = nums;
        vector<string> ans(size);
        // init the index array & sort them
        vector<int> index(size);
        for (int i = 0; i < size; ++i)  index[i] = i;
        quickSort(index, 0, size - 1);
        // assign the ranks
        for (int i = 0; i < size; ++i) {
            if (i <= 2) {
                ans[index[i]] = medals[i];
            } else {
                ans[index[i]] = to_string(i + 1);
            }
        }
        return ans;
    }

private:
    vector<int> scores;
    vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    
    void quickSort(vector<int> &index, int left, int right) {
        if (left >= right)  return;
        int mid = partition(index, left, right);
        quickSort(index, left, mid - 1);
        quickSort(index, mid + 1, right);
    }
    
    int partition(vector<int> &index, int left, int right) {
        int pivot = index[right];
        int low = left, high = right - 1;
        while (low <= high) {
            if (scores[index[low]] >= scores[pivot]) {
                ++low;
            } else {
                swap(index[low], index[high--]);
            }
        }
        swap(index[low], index[right]);
        return low;
    }
};