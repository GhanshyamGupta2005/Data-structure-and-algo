// class Solution {
// public:
//     bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check)
//     {
//         vis[node]=1;
//         // check[node]=0;
//         pathVis[node]=1;


//         for(auto it:graph[node])
//         {
//             if(!vis[it])
//             {
//               if(dfs(it,graph,vis,pathVis,check))
//               {
//                   check[node]=0;
//                   return true;
//               }
//               //also pathvisited
//               else if(pathVis[it])
//               {
//                      check[node]=0;
//                   return true;
//               }
//             }

//         }
//         pathVis[node]=0;
//         check[node]=1;//node is safe
//         return false;
//     }
//     


//        vector<int>pathVis(v,0);
//        vector<int>vis(v,0);
//        vector<int>check(v,0);//isse check kr lenge ki vo safe h ya nhi
//        vector<int>safenode;

//        for(int i=0;i<v;i++)
//        {
//            if(!vis[i])
//            {
//                dfs(i,graph,vis,pathVis,check);
//            }
//        }

//        for(int i=0;i<v;i++)
//        {
//            if(check[i]==1)safenode.push_back(i);
//        }
//           return safenode;
//     }
// };

// <-------------------------working-------------------------------------->

// aproch of loop detection in directed graph (if a node is in loop or leads to a loop will be marked as unsafe node)

// full code of loop detection in directed graph
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        check[node] = 0;
        pathVis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathVis, check)==true)
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1; // Mark the node as safe
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> pathVis(v, 0);
        vector<int> vis(v, 0);
        vector<int> check(v, -1); // Initialize all nodes as unchecked
        vector<int> safenode;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < v; i++) {
            if (check[i] == 1) safenode.push_back(i);
        }
        return safenode;
    }
};


// <-------------------------working-------------------------------------->





//<------------------------------------- working--------------------------->
// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         for (auto it : graph[node]) {
//             if (pathVis[it] || (!vis[it] && !dfs(it, graph, vis, pathVis, check))) {
//                 return false;
//             }
//         }

//         pathVis[node] = 0;
//         check[node] = 1; // Mark the node as safe
//         return true;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int v = graph.size();

//         vector<int> pathVis(v, 0);
//         vector<int> vis(v, 0);
//         vector<int> check(v, 0); // Indicates whether the node is safe or not
//         vector<int> safenode;

//         for (int i = 0; i < v; i++) {
//             if (!vis[i]) {
//                 dfs(i, graph, vis, pathVis, check);
//             }
//         }

//         for (int i = 0; i < v; i++) {
//             if (check[i] == 1) safenode.push_back(i);
//         }
//         return safenode;
//     }
// };
// <--------------------------------working----------------------------------------->
