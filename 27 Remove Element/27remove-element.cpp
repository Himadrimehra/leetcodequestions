class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Variable to keep track of the position for non-val elements
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // Move non-val element to the k-th position
            k++;
        }
    }
    return k;
}
    
};