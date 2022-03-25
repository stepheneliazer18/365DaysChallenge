class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int total = 0;
        vector<int> vect;
        for(int i = 0; i < costs.size(); i++) {
            total += costs[i][1];
            vect.push_back(costs[i][1] - costs[i][0]);
        }
        sort(vect.begin(), vect.end()); 
        for(int i = vect.size() - 1 ; i >= vect.size()/2 ; i--){
            total -= vect[i];
        }
        
        return total;     
    }
};
