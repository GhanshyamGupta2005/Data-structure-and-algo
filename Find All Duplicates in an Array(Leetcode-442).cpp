class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            int index = abs(num) - 1; // Adjust for zero-based indexing
            if (nums[index] < 0) {
                result.push_back(index + 1); // Add duplicate to result
            } else {
                nums[index] = -nums[index]; // Mark presence by negating
            }
        }

        return result;
    }
};
