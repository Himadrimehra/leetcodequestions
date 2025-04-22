class Solution {
public:
    int partition(vector<int>& nums, int sum, int n) {
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

        for (int i = 0; i <= n; i++) t[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= nums[i-1])
                    t[i][j] = (t[i-1][j-nums[i-1]] + t[i-1][j]) ;
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];

        if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;

        int sum1 = (target + sum) / 2;
        return partition(nums, sum1, n);
    }
};
