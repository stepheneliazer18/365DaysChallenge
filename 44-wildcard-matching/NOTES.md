Recursion:
TC:
SC:
​
class Solution {
public:
bool solve(int i, int j, string& s1, string& s2){
if(i<0){
if(j<0) return true;
for(int x=j;x>=0;x--){
if(s2[x] != '*') return false;
}
return true;
}
if(j<0){
if(i<0) return true;
return false;
}
if(s1[i] == s2[j] || s2[j] == '?') return solve(i-1,j-1,s1,s2);
else if(s2[j] == '*') return solve(i,j-1,s1,s2) || solve(i-1,j,s1,s2);
return false;
}
bool isMatch(string s1, string s2) {
int n = s1.size();
int m = s2.size();
return solve(n-1,m-1,s1,s2);
}
};
​
Memoization:
TC:
SC:
​
class Solution {
public:
bool solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
if(i<0){