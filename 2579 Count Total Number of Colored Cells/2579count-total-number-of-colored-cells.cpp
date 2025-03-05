class Solution {
public:
    long long coloredCells(int n) {
        int t=1;
        long long cell=1;
        while(t<=n)
        {
            cell=cell+4*(t-1);
            t++;
        }
        return cell;
    }
};