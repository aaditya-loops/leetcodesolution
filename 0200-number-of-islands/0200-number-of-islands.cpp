class Solution {
public:
    void number(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        grid[i][j]='0';
        if(i>0){
            if(grid[i-1][j]=='1'){
                number(grid,i-1,j,n,m);
            }

        }
        if(j<m-1){
            if(grid[i][j+1]=='1'){
                number(grid,i,j+1,n,m);
            }
        }
        if(i<n-1){
            if(grid[i+1][j]=='1'){
                number(grid,i+1,j,n,m);
            }
        }
        if(j>0){
            if(grid[i][j-1]=='1'){
                number(grid,i,j-1,n,m);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

       
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]=='1'){
                ans++;
                number(grid,i,j,n,m);
               }
            }
        }
        return ans;
    }
};