class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string cmn = strs[0];
        
        int ans = cmn.length()-1;
        
        for(int i=1;i<n;i++){
            int len = strs[i].length();
            int temp = min(len-1, ans);
            int j;
            for(j=0;j<=temp;j++){
                if(cmn[j] != strs[i][j]){
                    ans = j-1;
                    break;
                }
            }
            ans = j-1;
        }
        if(ans == -1) return "";
        return cmn.substr(0,ans+1);
    }
};