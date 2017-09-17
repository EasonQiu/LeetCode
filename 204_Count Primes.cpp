// Description:

// Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)  return 0;
        vector<bool> is_prime(n + 1, true);
        int square = sqrt(n);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!is_prime[i])  continue;
            ++count;
            if (i > square)  continue; //  may overflow
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        return count;
    }
};