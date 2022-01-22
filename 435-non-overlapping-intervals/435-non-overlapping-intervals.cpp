bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& vec) {
        if(!vec.size())return 0;
        sort(vec.begin(),vec.end(),cmp);
        
        int maxi = -1;
        vector<int> prev = vec[0];
        for(vector<int> it: vec){
            if(prev[1]>it[0]){
                maxi++;
            }
            else prev = it;
        }
        return maxi;
    }
};