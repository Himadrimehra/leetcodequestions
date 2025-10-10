class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word=strs[0];
        int lngth=word.size();

        for(int i=1;i<strs.size();i++){
                int cnt=0;
            for(int j=0;j<strs[i].size();j++){
                if(word[j]==strs[i][j]){ 
                    cnt++;
                }
                else{
                    break;
                }
            }
            lngth=min(cnt,lngth);
        }
    string ans="";
        for(int i=0;i<lngth;i++){
            ans+=word[i];
        }
        return ans;
        
    }
};