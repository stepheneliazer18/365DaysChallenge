// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int start;
        int end;
        int index;
    };
    struct{
        bool operator()(meeting m1, meeting m2) const{
            if(m1.end == m2.end) return m1.index < m2.index;
            return m1.end < m2.end;
        }
    }cmp;
    // bool cmp(struct meeting m1, meeting m2){
    //     if(m1.end == m2.end) return m1.index < m2.index;
    //     return m1.end < m2.end;
    // }
    int maxMeetings(int start[], int end[], int n){
        
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].index = i+1;
        }
        sort(meet,meet+n,cmp);
        
        int res = 0;
        int prev = 0;
        for(auto &it: meet){
            if(it.start > prev){
                res++;
                prev = it.end;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends