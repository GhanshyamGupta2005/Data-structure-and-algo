class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumCount;

        for (int num : nums) {
            prefixSumCount[sum]++;
            sum += num;
            count += prefixSumCount[sum - goal];
        }

        return count;
    }
};
