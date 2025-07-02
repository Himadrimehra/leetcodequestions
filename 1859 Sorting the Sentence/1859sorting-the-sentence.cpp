class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10);
        string temp;
        int count=0;
        int index=0;
        while(index<s.size())
        {
            if(s[index]==' ')
            {
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos-1]=temp;
                temp.clear();
                count++;
            }
            else 
            {
                temp=temp+s[index];
            }
            index++;
        }
        int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos-1]=temp;
                temp.clear();
                count++;
                string result;
                for(int i=0;i<count;i++)
                {
                    result+=ans[i];
                    if (i != count - 1) result += " ";
                }
                return result;
    }
};