class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int, int>> que; 
        set<pair<int,int>> s; 
        int n = graph.size(),final = ((1<<n)-1), temp, len = 0;
        
        for(int i=0;i<n;i++) que.push( {i, (1<<i)} );
        
        while(que.empty() == false){
            
            temp = que.size();
            while( temp ){
                auto p = que.front();
                que.pop();
                for(auto conn:graph[p.first]){
                    int mask = (1<<conn); 
                    int node = ( p.second & mask )? (p.second) : (p.second + mask);
                    if(node == final) return (len+1);
                    if( s.count({conn, node}) == 0 ){
                        que.push({conn, node});
                        s.insert({conn, node});
                    }
                }
                temp -= 1;
            }
            len += 1;
        }
        return 0;
    }
};