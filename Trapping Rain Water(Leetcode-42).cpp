class Solution {
public:
    int trap(vector<int>& height) {
      int Maxl=height[0];//from left to right
      int n=height.size();
      vector<int>v1;
      for(int i=0;i<n;i++)
      {
        if(height[i]>Maxl)Maxl=height[i];

        v1.push_back(Maxl);
      }  

      vector<int>v2;
    int  Maxr=height[n-1];
      for(int i=n-1;i>=0;i--)
      {
        if(height[i]>Maxr)Maxr=height[i];

        v2.push_back(Maxr);
      }
      reverse(v2.begin(),v2.end());
     int ans=0;
      for(int i=0;i<n;i++)
      {
               int x=min(v2[i],v1[i]);
               if(x>height[i])
               ans+=x-height[i];
      }
      return ans;
    }
};
