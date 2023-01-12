//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int N) {
        long long  n = N;
        long long s = (n*(n+1))/2 * (1LL);
        long long p = n*((n+1)*((2*n) + 1))/6 * (1LL);
        
        for(int i=0;i<n;i++){
            s -= (long long )arr[i];
            p -= (long long )arr[i] * (long long )arr[i];
        }
        
        int *a = new int[2];
        
        a[1] = (s + (p/s))/2;
        a[0] = a[1] - s;
        
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends