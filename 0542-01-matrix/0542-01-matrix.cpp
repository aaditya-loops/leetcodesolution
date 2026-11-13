class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,-1));
        int idx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    dist[i][j]=0;
                    continue;
                }

                for(int k=0;k<4;k++){
                    int x=i+idx[k][0];
                    int y=j+idx[k][1];
                    if(x>=0 && x<n && y>=0 && y<m){
                        if(mat[x][y]==0){
                            dist[i][j]=1;
                            q.push({i,j});
                            vis[i][j]=1;
                            break;
                        }
                    }
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+idx[k][0];
                int y=j+idx[k][1];
                if(x>=0 && x<n && y>=0 && y<m){
                    if(vis[x][y]==0){
                        dist[x][y]=dist[i][j]+1;
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        return dist;
    }
};