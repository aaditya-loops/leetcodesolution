class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> set(n, -1);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (set[i] == -1) {
                set[i] = 0;
                for (auto it : graph[i]) {
                    set[it] = 1;
                    q.push(it);
                }
            }

            while (q.size()) {
                int x = q.front();
                q.pop();
                int y;
                if(set[x]==1){
                    y=0;

                }
                else{
                    y=1;
                }
                for (auto it : graph[x]){
                    if(set[it]==-1){
                        set[it]=y;
                        q.push(it);
                    }
                    else if(set[it]==set[x]){
                        return false;
                    }
                         
                }
                    
            }
        }
        return true;
    }
};