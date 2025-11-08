class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long myPow(long long x, long long n) {
        long long ans = 1;
        x = x % MOD;
        while (n) {
            if (n % 2) {
                ans = (ans * x) % MOD;
                n--;
            } else {
                x = (x * x) % MOD;
                n /= 2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        return (myPow(5, (n + 1) / 2) * myPow(4, n / 2)) % MOD;
    }
};
