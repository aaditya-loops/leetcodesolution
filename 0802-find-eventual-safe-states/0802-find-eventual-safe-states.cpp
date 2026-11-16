class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>innode(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
               innode[i]=graph[i].size();
               if(innode[i]==0){
                q.push(i);
               }
               for(auto it:graph[i]){
                adj[it].push_back(i);
               }


        }
        while(q.size()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                innode[it]--;
                if(innode[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};