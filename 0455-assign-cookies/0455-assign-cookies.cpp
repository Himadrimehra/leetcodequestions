class Solution {
public:
    int findContentChildren(vector<int>& childern, vector<int>& cookies) {
        sort(childern.begin(),childern.end());
        sort(cookies.begin(),cookies.end());
        int i=0;
        int j=0;
     while(i<cookies.size() && j<childern.size())
     {
        if(cookies[i]>=childern[j])
        {
            j++;
        }
        i++;
     }
     return j;
    }
};