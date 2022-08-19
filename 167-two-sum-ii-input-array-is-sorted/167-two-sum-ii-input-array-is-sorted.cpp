class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i=0;i<n;i++){
            int need = target-numbers[i];
            
            int l = i+1;
            int r = n-1;
            
            while(l<=r){
                int mid = (l+r)/2;
                
                if(numbers[mid] == need) return {i+1,mid+1};
                
                if(need < numbers[mid]) r = mid-1;
                else l = mid+1;
            }
            
        }
        return {0,1};
    }
};