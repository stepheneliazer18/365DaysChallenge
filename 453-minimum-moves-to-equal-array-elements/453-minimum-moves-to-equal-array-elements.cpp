//              Brute Force -   TLE
// class Solution {
// public:
//     bool isequal(vector<int>& nums){
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]!=nums[i+1])return false;
//         }
//         return true;
//     }
//     int minMoves(vector<int>& nums) {
//         int n = nums.size();
        
//         int cnt = 0;
//         while(!isequal(nums)){
//             sort(nums.begin(),nums.end());
//             for(int i=0;i<n-1;i++) nums[i]++;
//             cnt++;
//         }
//         return cnt;
//     }
// };

//              Optimized - O(n) - AC
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        int mini = *min_element(nums.begin(),nums.end());
        
        return sum - (n * mini);
    }
};