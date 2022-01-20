// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> st;
        for(int i=0;i<N;i++) st.insert(arr[i]);
        auto it = st.begin();
        int cnt = 0;
        int i = *it;
        int maxi = 0;
        for(auto &it: st){
            if(it!=i){
                cnt = 0;
                i = it;
            }
            cnt++;i++;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends