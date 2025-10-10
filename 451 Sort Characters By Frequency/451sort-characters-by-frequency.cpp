class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for (auto &i : s) {
            m[i]++;
        }

        string ans = "";
        while (!m.empty()) {
            char max_char = 0;
            int max_freq = 0;
            for (auto const& c : m) {
                if (c.second > max_freq) {
                    max_freq = c.second;
                    max_char = c.first;
                }
            }
            for (int i = 0;i<max_freq;i++) {
                ans += max_char;
            }
            m.erase(max_char);
        }
        return ans;
    }
};