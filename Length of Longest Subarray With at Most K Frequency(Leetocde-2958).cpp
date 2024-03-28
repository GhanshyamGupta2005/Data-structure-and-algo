// <---------------------O(n^2) till 870/992 case working ---------------------------->

// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//       int maxSize = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             unordered_map<int, int> freqMap;
//             for (int j = i; j < nums.size(); j++) {
//                 if (freqMap[nums[j]] < k) {
//                     freqMap[nums[j]]++;
//                     maxSize = max(maxSize, j - i + 1);
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return maxSize;
//     }
// };




//   https://www.youtube.com/watch?v=qCwgGHYImv4&ab_channel=AyushRao
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int maxSize = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;

            // Shrink the window from the left if necessary
            while (freqMap[nums[left]] > k) {
                freqMap[nums[left]]--;
                // if (freqMap[nums[left]] == 0)
                //     freqMap.erase(nums[left]);
                maxSize = max(maxSize, right - left + 1);
                left++;
            }

           
        }

        return maxSize;
    }
};

// <--------------------------Working------------------------------------------->

// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& v, int k) {
//         int n=v.size();
//         map<int,int>m;
//         int i=0,j=0;
//         int ans=0;
//         while(i<n && j<n)
//         {
//             m[v[j]]++;
//             while(m[v[j]]>k)
//             {
//                 m[v[i]]--;
//                 i++;
//             }
//             ans=max(ans,j-i+1);
//             j++;
//         }
//         return ans;
//     }
// };
