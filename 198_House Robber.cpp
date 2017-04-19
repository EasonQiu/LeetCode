class Solution {
public:
    int rob(vector<int>& nums) {
        int toDo = 0, notToDo = 0, tmp;
        for (int i = 0; i < nums.size(); ++i) {
            tmp = max(toDo, notToDo);
            toDo = notToDo + nums[i];
            notToDo = tmp;
        }
        return max(toDo, notToDo);
    }
};