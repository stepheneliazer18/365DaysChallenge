// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    struct{
        bool operator()(pair<int,int> p1, pair<int,int> p2)const{
            return p1.second < p2.second;
        }
    }cmp;
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        
        int maxi = 1;
        int prev = vec[0].second;
        for(int i=1;i<n;i++){
            if(vec[i].first>prev){
                maxi++;
                prev = vec[i].second;
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends