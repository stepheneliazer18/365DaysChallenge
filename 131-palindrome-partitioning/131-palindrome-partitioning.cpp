class Solution {
public:
    bool ispalindrome(string &str, int i, int j){
        if(i>=j) return true;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;j--;
        }
        return true;
    }

    vector<vector<string>> ans;
    void solve(string str, int index, vector<string> vec){

        if(index==str.length()){
            ans.push_back(vec);
            return;
        }

        for(int k = index; k<str.length(); k++){
            if(ispalindrome(str,index,k)){
                vec.push_back(str.substr(index,k-index+1));
                solve(str,k+1,vec);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
};