class Solution {
public:
    void number(vector<int>&vis,vector<int> adj[],int i){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==-1){
                number(vis,adj,it);
            }
            
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); 
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }

        }
        vector<int>vis(n,-1);
        int ans=0;
        int i=0;
        while(i<n){
            if(vis[i]==-1){
                ans++;
                number(vis,adj,i);
            }
            i++;
        }
        return ans;
    }
};