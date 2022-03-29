// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
static bool cmp(string &s1,string &s2){
        return s1+s2 > s2+s1;
    }
	string printLargest(vector<string> &vec) {
        sort(vec.begin(),vec.end(),cmp);
        
        string ans;
        for(auto &it: vec) ans += it;
        if(ans[0]== '0') return "0";
        return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends