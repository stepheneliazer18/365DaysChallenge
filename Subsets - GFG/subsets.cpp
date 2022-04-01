// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>> vec;
    void func(vector<int> & A,int i,  vector<int> &cur){
        if(i==A.size()){
            vec.push_back(cur);
            return;
        }
        
        func(A,i+1,cur);
        cur.push_back(A[i]);
        func(A,i+1,cur);
        cur.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A){
        vector<int> cur;
        func(A,0,cur);
        sort(vec.begin(),vec.end());
        return vec;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends