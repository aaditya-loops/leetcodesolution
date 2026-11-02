class Solution {
public:
void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
    grid[i][j]=-1;
    if(i>0){
        if(grid[i-1][j]==1){
            dfs(grid,i-1,j,n,m);
        }

    }
    if(j<m-1){
        if(grid[i][j+1]==1){
            dfs(grid,i,j+1,n,m);
        }

    }
    if(i<n-1){
        if(grid[i+1][j]==1){
            dfs(grid,i+1,j,n,m);

        }

    }
    if(j>0){
        if(grid[i][j-1]==1){
            dfs(grid,i,j-1,n,m);
        }
    }
    return;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i,n,m);
            }
            if(grid[n-1][i]==1){
                dfs(grid,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0,n,m);
            }
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1,n,m);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};