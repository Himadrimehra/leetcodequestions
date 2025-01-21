class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int index = 1;  // Start from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];  // Place the unique element at the correct index
                index++;  // Move the index for the next unique element
            }
        }
        
        return index;  // The number of unique elements
    }
};