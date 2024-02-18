class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& image, int color, int starting, vector<vector<int>>& v) {
        // vis[row][col] = 1;
         v[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int n = q.front().first;
            int m = q.front().second;
            int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = n + directions[i][0];
                int y = m + directions[i][1];
                if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == starting && !vis[x][y]) {
                    v[x][y] = color;
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
 #pragma GCC optimize ("O2")
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    int row = image.size();
    int col = image[0].size();
    int starting = image[sr][sc];
    vector<vector<int>> vis(row, vector<int>(col, 0));
    vector<vector<int>> v = image; // Initialize v with the original image
    bfs(sr, sc, vis, image, color, starting, v); // Perform flood fill from starting pixel
    
    return v;
}

};
