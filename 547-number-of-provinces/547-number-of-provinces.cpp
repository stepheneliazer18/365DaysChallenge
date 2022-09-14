class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        int cnt = 0;
        
        vector<int> visited(V+1,0);
        
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int i=0;i<V;i++){
                        if(adj[node-1][i] == 1 && i != node-1 && !visited[i+1]){
                            visited[i+1] = 1;
                            q.push(i+1);
                        }
                    }
                }
                cnt++;
            }
        }
        
        return cnt;
    }
};