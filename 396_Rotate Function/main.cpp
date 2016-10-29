#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, Fk = 0, maxFk = 0, n = A.size();
        for (int i = 0; i < n; i++){
            sum += A[i];
            Fk += i * A[i];
        }
        maxFk = Fk;
        for (int k = 1; k < n; k++){
            Fk = Fk + sum - n * A[n - k];
            if (Fk > maxFk) maxFk = Fk;
        }
        return maxFk;
    }
};

int main() {
    int num[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> A(num, num+10);

    Solution s;
    cout << s.maxRotateFunction(A);

}