class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int ans=0; 0 not a  -ve no.
        int ans=1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)

        {
            if(nums[i]<=0)
            continue;
            if(nums[i]==ans)
            ans++;
            else if(nums[i]>ans)
             return ans;
            // break;
        }
          return ans;
    }
};
