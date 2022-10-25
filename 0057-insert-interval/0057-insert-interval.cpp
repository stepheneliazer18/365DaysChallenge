class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> nextCompare = newInterval;
        vector<vector<int>> result;
        int i = 0;
        
        while (i < intervals.size()) {
            if(intervals[i][1] < nextCompare[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > nextCompare[1]) {
                result.push_back(nextCompare);
                while (i < intervals.size()) {
                    result.push_back(intervals[i]);
                    i++;
                }
                return result;
            } else {
                nextCompare[1] = max(nextCompare[1],intervals[i][1]);
                nextCompare[0] = min(nextCompare[0],intervals[i][0]);
            }
            
            i++;
        }
        
        result.push_back(nextCompare);
        return result;
    }
};