#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isExsit(const vector<int> &element, const vector<vector<int>> &sameLength){
        bool flag = false, isEqual;
        for (int i = 0; i < sameLength.size(); i++){
            isEqual = true;
            for (int j = 0; j < element.size(); j++)
                if (element[j] != sameLength[i][j]){
                    isEqual = false; break;
                }
            if (isEqual) {
                flag = true; break;
            }
        }
        return flag;
    }

    void addIndex(vector<int> &indexs, int length, unsigned int size){
        int pos = length-1;
        while (indexs[pos] == pos + size - length)   pos--;
        indexs[pos++]++;
        for (int i = pos; i < length; i++)
            indexs[i] = indexs[i-1] + 1;

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results, sameLength;
        vector<int> element;
        sort(nums.begin(),nums.end());

        if (nums.size() == 0) return results;
        results.push_back(element);

        for (int length = 1; length <= nums.size(); length++){
            sameLength.clear();
            vector<int> indexs(length), endIndexs(length);
            for (int i = 0; i < length; i++) {
                indexs[i] = i;  endIndexs[i] = nums.size() - length + i;
            }
            element.assign(nums.begin(), nums.begin() + length);
//            sort(element.begin(),element.end());
            sameLength.push_back(element);

            while (indexs != endIndexs){
                element.clear();
                addIndex(indexs, length, nums.size());
                for (int i = 0; i < indexs.size(); i++) {
                    element.push_back(nums[indexs[i]]);
                }
//                sort(element.begin(),element.end());
                if (!isExsit(element, sameLength)) {
                    sameLength.push_back(element);
                }
            }

            for (int i = 0; i < sameLength.size(); i++)
                results.push_back(sameLength[i]);
        }

        return results;
    }
};

int main() {
    int a[] = {4,4,4,1,4};
    vector<int> nums(a,a+5);

    Solution s;
    s.subsetsWithDup(nums);

    return 0;
}