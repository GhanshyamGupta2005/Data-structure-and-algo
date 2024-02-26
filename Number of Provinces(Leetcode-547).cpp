class Solution {
private:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& adjL) {
        vis[i] = 1;
        for (auto it : adjL[i]) {
            if (!vis[it])
                dfs(it, vis, adjL);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<vector<int>> adjL(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, adjL);
            }
        }
        return count;
    }
};
