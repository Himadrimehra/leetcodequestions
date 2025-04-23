class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int sum=amount; 
     int n = coins.size();
    if (n == 0) {
    if (sum == 0)
        return 0;
    else
        return -1;
}

    int t[n+1][sum+1];

    for(int i = 0; i <= n; i++) t[i][0] = 0;
    for(int j = 1; j <= sum; j++) t[0][j] = INT_MAX - 1;

    for(int j = 1; j <= sum; j++) {
        if(j % coins[0] == 0)
            t[1][j] = j / coins[0];
        else
            t[1][j] = INT_MAX - 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(coins[i-1] <= j)
                t[i][j] = min(t[i][j - coins[i-1]] + 1, t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return (t[n][sum] == INT_MAX - 1) ? -1 : t[n][sum];
    }
};