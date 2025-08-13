class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        // Compute row-wise prefix sums once, outside other loops
        for (int row = 0; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        // Enumerate start and end columns correctly
        for (int startcol = 0; startcol < cols; ++startcol) {
            for (int j = startcol; j < cols; ++j) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cumsum = 0;
                for (int row = 0; row < rows; ++row) {
                    int val = matrix[row][j] - (startcol > 0 ? matrix[row][startcol - 1] : 0);
                    cumsum += val;
                    if (mp.count(cumsum - target)) {
                        result += mp[cumsum - target];
                    }
                    mp[cumsum]++;
                }
            }
        }

        return result;
    }
};
