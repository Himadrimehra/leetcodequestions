class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
    vector<int> cnt(n * n + 1, 0); // Initialize a count array to store frequency of numbers
    vector<int> result(2);  // To store the repeated and missing values

    // Count occurrences of each number in the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cnt[grid[i][j]]++;
        }
    }

    // Find the repeated and missing numbers
    for (int i = 1; i <= n * n; ++i) {
        if (cnt[i] == 2) {
            result[0] = i;  // Repeated number
        }
        if (cnt[i] == 0) {
            result[1] = i;  // Missing number
        }
    }

    return result;

    }
};