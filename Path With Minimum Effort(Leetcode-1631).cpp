// 38

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {


priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//{diff,{row,col}}
 pq.push({0,{0,0}});
 int m= heights.size();
 int n= heights[0].size();
 vector<vector<int>>dis(m,vector<int>(n,1e9));
dis[0][0]=0;
   int dR[]={-1,0,1,0};
   int dC[]={0,1,0,-1};

//    // checking row=1
//    if(m==1 &&n!=1)
//    return heights[0][n-1];
 while(!pq.empty())
 {
   auto it=pq.top();
   pq.pop();
   int dist=it.first;
   int row=it.second.first;

   int col=it.second.second;
// check after pop out
if(row==m-1&&col==n-1)
return dist;


   for(int i=0;i<4;i++)
   {
       int newRow=row+dR[i];
       int newCol=col+dC[i];

    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n)
    {
         int newEffort=max(abs(heights[row][col]-heights[newRow][newCol]),dist);

        if(newEffort<dis[newRow][newCol])
        {   dis[newRow][newCol]=newEffort;
        pq.push({newEffort,{newRow,newCol}});
        }
    }
   }
     }
      return 0;
    }
};
