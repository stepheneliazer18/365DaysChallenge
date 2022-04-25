class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        
        vector<vector<int>> vec;
        
        for(int i=0;i<n;i++){
            if(vec.empty() || vec.back()[1] < intervals[i][0]){
                vec.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                vec.back()[1] = max(vec.back()[1],intervals[i][1]);
            }
        }
        return vec;
    }
};