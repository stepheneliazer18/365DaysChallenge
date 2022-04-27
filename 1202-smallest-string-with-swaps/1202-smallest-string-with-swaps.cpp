class Solution {
public:    
    int findPar(vector<int>& parent, int num){
        if(num == parent[num]) return num;
        return parent[num] = findPar(parent, parent[num]);
    }
    
    void makeUnion(vector<int>& parent, vector<int>& rank, int u, int v){
        int u_par = findPar(parent, u);
        int v_par = findPar(parent, v);
        
        if(u_par == v_par) return;
        
        if(rank[u_par] < rank[v_par]){
            parent[u_par] = v_par;
        }
        else if(rank[v_par] < rank[u_par]){
            parent[v_par] = u_par;
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto &it: pairs){
            int u = findPar(parent,it[0]);
            int v = findPar(parent,it[1]);
            
            if(u != v) makeUnion(parent,rank,u,v);
        }
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++) mp[findPar(parent, i)].push_back(i);
        
        for(auto &it: mp){
            string temp = "";
            for(auto &it1: it.second) temp.push_back(s[it1]);
            sort(temp.begin(),temp.end());
            int x = 0;
            for(auto &it1: it.second) s[it1] = temp[x++];
        }
        
        return s;
    }
};