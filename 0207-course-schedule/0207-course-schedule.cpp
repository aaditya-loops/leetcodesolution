class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int i,vector<int>& vis,vector<int>& vispath){
        vis[i]=1;
        vispath[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==1){
                if(vispath[it]==1){
                    return false;
                }
                continue;
            }
            else{
                if(!dfs(adj,it,vis,vispath)){
                    return false;
                }
                continue;
            
            }
        }
        vispath[i]=0;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>vispath(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(!dfs(adj,i,vis,vispath)){
                    return false;
                }
            }
        }
        return true;
    }
};