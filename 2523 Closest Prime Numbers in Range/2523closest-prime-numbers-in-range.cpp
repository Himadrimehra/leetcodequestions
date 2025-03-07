class Solution {
public:
  vector<bool> sieve(int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
         vector<bool> isPrime = sieve(right); // Find all primes up to `right`
        
        // Collect all primes within the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // If there are less than 2 primes, return [-1, -1]
        if (primes.size() < 2) {
            return {-1, -1};
        }

        // Find the closest pair of primes
        int minDiff = INT_MAX;
        pair<int, int> closestPair;
        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i - 1], primes[i]};
            }
        }

        return {closestPair.first, closestPair.second};
    }
};
