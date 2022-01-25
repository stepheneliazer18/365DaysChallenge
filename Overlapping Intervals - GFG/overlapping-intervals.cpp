// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends