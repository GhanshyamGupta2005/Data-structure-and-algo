// Hint excat k no=atmost k distict - atmost (k-1) distinct

class Solution {
public:
    int helper(vector<int>& nums, int k) // atmost k distict 
    {
        unordered_map<int,int>map;
        int l=0,r=0,ans=0;

        while(r<nums.size())
        {
            map[nums[r]]++;

            while(map.size()>k&&l<=r)
            {
                map[nums[l]]--;
                if( map[nums[l]]==0)map.erase(nums[l]);
                l++;
            }

                ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return helper(nums,k)-helper(nums,k-1);//atmost k distict - atmost (k-1) distinct
    }
};
