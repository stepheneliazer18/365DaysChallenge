class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto &it: stones) pq.push(it);
        
        while(!pq.empty()){
            if(pq.size() == 1){
                return pq.top();
            }
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            
            if(n1!=n2) pq.push(abs(n1-n2));
        }
        return 0;
    }
};