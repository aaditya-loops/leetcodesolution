class Solution {
public:
    int f(int i,int j,int k,int n,int m,vector<vector<vector<int>>> & dp,vector<vector<int>>& grid){
        if(k>=n){
            return 0;
        }
        if(dp[k][i][j]!=-1){
            return dp[k][i][j];
        }
        int maxi=0;
        int x;
        if(i==j){
            x=grid[k][i];
        }
        else{
            x=grid[k][i]+grid[k][j];
        }
        for(int a=i-1;a<=i+1;a++){
            if(a<0 || a>=m){
                continue;
            }
            else{
                for(int b=j-1;b<=j+1;b++){
                    if(b<0 || b>=m){
                        continue;
                    }
                    else{
                        maxi=max(maxi,x+f(a,b,k+1,n,m,dp,grid));
                    }
                }
            }
        }
        dp[k][i][j]=maxi;
        return maxi;
    }


    int cherryPickup(vector<vector<int>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
     return f(0,m-1,0,n,m,dp,grid);
    }
};