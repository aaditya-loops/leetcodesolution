class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==1){
            vector<int>ans(1,0);
            return ans;
        }
        vector<vector<int>>adj(numCourses);
        vector<int>in_nodes(numCourses,0);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            in_nodes[it[0]]++;
            
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(in_nodes[i]==0){
                q.push(i);

            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x]){
                in_nodes[it]--;
                if(in_nodes[it]==0){
                    q.push(it);
                }

            }

        }
        if(ans.size()<numCourses){
            ans.clear();

        }
        return ans;

    }
};