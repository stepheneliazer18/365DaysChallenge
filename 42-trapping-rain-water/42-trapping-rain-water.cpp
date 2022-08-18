class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int l = 0;
        int r = n-1;
        
        int left_max = 0;
        int right_max = 0;
        
        int ans = 0;
        
        while(l<r){
            left_max = max(left_max,height[l]);
            right_max = max(right_max,height[r]);
            
            if(height[l] <= height[r]){
                ans += min(left_max,right_max) - height[l];
                l++;
            }
            else{
                ans += min(left_max,right_max) - height[r];
                r--;
            }
        }        
        
        return ans;
    }
};