class Solution {
public:
    bool loadWithInDays(vector<int>& weights, int capacity, int days) {
        int countday = 1; 
        int sum = 0;
        for (int w : weights) {
            if (w > capacity) return false; // single weight too big
            sum += w;
            if (sum > capacity) {
                countday++;
                sum = w; // start new day
            }
        }
        return countday <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for(int w : weights) r += w;
        int ans = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(loadWithInDays(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
