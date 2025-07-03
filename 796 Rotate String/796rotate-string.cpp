class Solution {
public:
 void rotateclockwise(string & s)
    {
     char c=s[s.size()-1];
     int index=s.size()-2;
     while(index>=0)
     {
         s[index+1]=s[index];
         index--;
     }
     s[0]=c;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        {
            return 0;
        }
        string clockwise=s;
        for(int i=0;i<s.size();i++)
        {
            rotateclockwise(clockwise);
            if(clockwise==goal)
            {
                return 1;
            }
        }
        return 0;
    }
};