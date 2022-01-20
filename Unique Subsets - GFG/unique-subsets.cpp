// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> nums, int n)
    {
        set<vector<int>> res;
        for(int i=0;i<pow(2,n);i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((i & 1<<j)!=0){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto &it: res){
            ans.push_back(it);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends