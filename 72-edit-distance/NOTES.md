Recursion:
TC: O(3^N * 3^M) [Exponential]
SC: O(N+M) [Auxiliary Space]
​
class Solution {
public:
int solve(int i, int j, string& s1, string& s2){
if(i < 0) return j+1;
if(j < 0) return i+1;
if(s1[i] == s2[j]) return solve(i-1,j-1,s1,s2);
else{
return 1 + min(
solve(i-1,j,s1,s2), // Delete
min(
solve(i,j-1,s1,s2), // Insert
solve(i-1,j-1,s1,s2) // Replace
)
);
}
}
int minDistance(string s1, string s2) {
int n = s1.size();
int m = s2.size();
return solve(n-1,m-1,s1,s2);