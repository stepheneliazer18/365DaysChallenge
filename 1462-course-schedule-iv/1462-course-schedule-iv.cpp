class Solution {
private:
    int findlevel(map<int,vector<int>>& mp, int node){
        for(auto &it: mp){
            int cur = it.first;
            for(auto &it1: it.second){
                if(it1 == node) return cur;
            }
        }
        return -1;
    }
    bool cango(int src, int target, vector<int> adj[], vector<int>& visited){
        visited[src] = 1;
        
        if(src == target) return true;
        
        for(auto &it: adj[src]){
            if(!visited[it]){
                if(cango(it,target,adj,visited)) return true;
            }
        }
        
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int> adj[n];
        
        for(auto &it: prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }
        
        map<int,vector<int>> mp;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push({i,0});
                mp[0].push_back(i);
            }
        }
        
        vector<int> topo;
        
        
        while(!q.empty()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            topo.push_back(node);
            
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push({it,level+1});
                    mp[level+1].push_back(it);
                }
            }
        }
        
        
        // for(auto &it: topo) cout<<it<<" ";cout<<endl;
        vector<bool> res;
        // for(auto &it: mp){
        //     cout<<it.first<<" -> ";
        //     for(auto &it1: it.second) cout<<it1<<" ";cout<<endl;
        // }
        for(auto &it: queries){
            int u = it[0];
            int v = it[1];
            
            vector<int> visited(n,0);
            if(cango(u,v,adj,visited)) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};

/*

2
[[1,0]]
[[0,1],[1,0]]
2
[]
[[1,0],[0,1]]
3
[[1,2],[1,0],[2,0]]
[[1,0],[1,2]]
5
[[0,1],[1,2],[2,3],[3,4]]
[[0,4],[4,0],[1,3],[3,0]]
4
[[2,3],[2,1],[0,3],[0,1]]
[[0,1],[0,3],[2,3],[3,0],[2,0],[0,2]]

*/