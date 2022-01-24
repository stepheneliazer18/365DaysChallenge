// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> vec;
        set<int>st;
        
        sort(arr,arr+n);
    
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])
            vec.push_back(arr[i]);
        }
        
        for(int s:vec){
            st.insert(s);
        }
        
        vec.clear();
        for(int s:st){
            vec.push_back(s);
        }
        if(vec.size()==0) vec.push_back(-1);
        return vec;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends