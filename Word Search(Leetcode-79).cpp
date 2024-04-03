class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int i,int j,int ptr,int len,vector<vector<int>>&visited,int rows,int cols){
        if(ptr==len) return true;
        if(i<rows-1 && visited[i+1][j]==-1 && board[i+1][j]==word[ptr]){
            visited[i+1][j]=1;
            if(helper(board,word,i+1,j,ptr+1,len,visited,rows,cols)) return true;
            else visited[i+1][j]=-1;            
        } 
        if(i>0 && visited[i-1][j]==-1 && board[i-1][j]==word[ptr]){
            visited[i-1][j]=1;
            if(helper(board,word,i-1,j,ptr+1,len,visited,rows,cols)) return true;
            else visited[i-1][j]=-1;
        } 
        if(j<cols-1 && visited[i][j+1]==-1 && board[i][j+1]==word[ptr]){
            visited[i][j+1]=1;
            if(helper(board,word,i,j+1,ptr+1,len,visited,rows,cols)) return true;
            else visited[i][j+1]=-1;
        } 
        if(j>0 && visited[i][j-1]==-1 && board[i][j-1]==word[ptr]){
            visited[i][j-1]=1;
            if(helper(board,word,i,j-1,ptr+1,len,visited,rows,cols)) return true;
            else visited[i][j-1]=-1;
        } 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    visited.clear();
                    visited.resize(m,vector<int>(n,-1));
                    visited[i][j]=1;
                    if(helper(board,word,i,j,1,word.size(),visited,m,n)) return true;
                    else continue;
                }
            }
        }
        return false;        
    }
};
