class Solution {
public:
    int compareVersion(string version1, string version2) {

        stringstream ss1(version1);
        stringstream ss2(version2);

        string token1, token2;

        while (true) {

            int num1 = 0;
            int num2 = 0;

            bool hasToken1 = false;
            bool hasToken2 = false;

            if (getline(ss1, token1, '.')) {
                hasToken1 = true;
                num1 = stoi(token1);
            } else {
                hasToken1 = false;
                num1 = 0;
            }

            if (getline(ss2, token2, '.')) {
                hasToken2 = true;
                num2 = stoi(token2);
            } else {
                hasToken2 = false;
                num2 = 0;
            }

            if (num1 < num2) {
                return -1;
            }
            else if (num1 > num2) {
                return 1;
            }

            // If both version strings are completely processed
            if (hasToken1 == false && hasToken2 == false) {
                break;
            }
        }

        return 0;
    }
};