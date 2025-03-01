class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> a;
        int i = 0; int j=0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                a.push_back(nums1[i++]);
            } else {
                a.push_back(nums2[j++]);
            }
        }
        while (i < n1) {
            a.push_back(nums1[i++]);
        }
        while (j < n2) {
            a.push_back(nums2[j++]);
        }
        int m = a.size();
        if (m % 2 == 0) {
            return (a[m / 2 - 1] + a[m / 2]) / 2.0;
        } else {
            return a[m / 2];
        }
    }
};
