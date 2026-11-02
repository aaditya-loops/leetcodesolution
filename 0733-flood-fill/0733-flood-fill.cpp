class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int test=image[sr][sc];
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        image[sr][sc]=color;
        q.push(pair(sr,sc));
        while(!q.empty()){
            int x=q.size();
            
            for(int i=0;i<x;i++){
                int a=q.front().first,b=q.front().second;
                q.pop();
                
                if(a>0){
                    if(image[a-1][b]==test && image[a-1][b]!=color){
                        image[a-1][b]=color;
                        q.push(pair(a-1,b));

                        
                    }
                
                }
                if(b<m-1){
                    if(image[a][b+1]==test && image[a][b+1]!=color){
                        image[a][b+1]=color;
                        q.push(pair(a,b+1));
                    }
                }
                if(a<n-1){
                    if(image[a+1][b]==test && image[a+1][b]!=color){
                        image[a+1][b]=color;
                        q.push(pair(a+1,b));
                    }
                }
                if(b>0){
                    if(image[a][b-1]==test && image[a][b-1]!=color){
                        image[a][b-1]=color;
                        q.push(pair(a,b-1));
                    }
                }



            }
        }
        return image;
    }
};