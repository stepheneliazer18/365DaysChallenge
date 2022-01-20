// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string str){
		    vector<string> res;
            for(int i=1;i<pow(2,str.length());i++){
                string temp;
                for(int j=0;j<str.size();j++){
                    if((i & 1<<j)!=0){
                        temp+=str[j];
                    }
                }
                res.push_back(temp);
            }
            sort(res.begin(),res.end());
            return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends