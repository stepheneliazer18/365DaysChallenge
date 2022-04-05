class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int answer = 0;
        
        int left = 0;
        int right = n-1;
        while(left < right){
            answer = max(answer, (right-left)*min(height[left],height[right]));    
            if(height[left] < height[right]) left++;
            else right--;
        }
        return answer;
    }
};