// <----------------------------Working till 162------------------------->

// class Solution {
// public:
//     long long countSubarrays(std::vector<int>& nums, int k) {
//         int maxEle = *std::max_element(nums.begin(), nums.end());
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             int c = 0;

//             for (int j = i; j < nums.size(); j++) {
//                 if (nums[j] == maxEle) {
//                     c++;
//                 }
//                 if (c == k) {
//                     count++;
//                 }
//                 if (c > k && nums[j] == maxEle) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


// <--------------------Using sliding windows------------------------>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {

        long long int maxEle = *std::max_element(nums.begin(), nums.end());
        
       long long int right=0;long long int left=0;long long int ans=0;long long int count=0;

        while(right<nums.size())
        {
            if(nums[right]==maxEle)count++;

            while(count>=k)
            {

                if(nums[left]==maxEle)count--;
                left++;

                ans+=nums.size()-right;
            }
            right ++;
        }

        return ans;
    }
};
