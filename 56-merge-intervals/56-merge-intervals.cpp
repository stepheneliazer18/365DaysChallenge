class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> stack;
        stack.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = stack.top();
            if(intervals[i][0] <= temp[1] && intervals[i][1] <= temp[1]) continue;
            if(intervals[i][0] <= temp[1]){
                stack.pop();
                stack.push({temp[0],intervals[i][1]});
            }
            else stack.push(intervals[i]);
        }
        vector<vector<int>> res;
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};