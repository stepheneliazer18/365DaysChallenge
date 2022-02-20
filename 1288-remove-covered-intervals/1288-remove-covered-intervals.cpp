bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]) return v1[1] > v2[1];
    return v1[0] < v2[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        
        int res = n;
        int i = 0;
        int j = 1;
        while(j<n){
            if(nums[i][1] >= nums[j][1]){
                res--;
                j++;
            }
            else i++;
            if(i==j) j++;
        }
        
        return res;
    }
};