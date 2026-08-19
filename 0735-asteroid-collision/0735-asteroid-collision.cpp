class Solution {
    stack<int> st;

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            bool alive = true;

            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                
                if (abs(st.top()) > abs(asteroids[i])) {
                    alive = false;
                    break;
                }
                
                else if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop();
                }
                
                else {
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};