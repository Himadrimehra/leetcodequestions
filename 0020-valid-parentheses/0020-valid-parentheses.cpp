class Solution {
    stack<char> sk;

public:
    bool isValid(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++) {

          
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sk.push(s[i]);
            }

           
            else {
                if(sk.empty())
                    return false;

                if((s[i] == ')' && sk.top() != '(') ||
                   (s[i] == '}' && sk.top() != '{') ||
                   (s[i] == ']' && sk.top() != '[')) {
                    return false;
                }

                sk.pop();
            }
        }

       
        return sk.empty();
    }
};