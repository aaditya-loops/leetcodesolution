class Solution {
public:
    void dfs(int i,int j,int idx[][2],vector<vector<char>> & board,int n,int m,vector<vector<int>>& vis ){
        
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+idx[k][0];
            int y=j+idx[k][1];
            if(x>=0 && x<n && y>=0 && y<m){
                if(board[x][y]=='O' && vis[x][y]==0){
                    dfs(x,y,idx,board,n,m,vis);
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int idx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && vis[0][i]==0){
                dfs(0,i,idx,board,n,m,vis);
            
            }
            if(board[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(n-1,i,idx,board,n,m,vis);
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,idx,board,n,m,vis);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,idx,board,n,m,vis);
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};