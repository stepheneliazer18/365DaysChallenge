class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int ctr=0;
         
        for(int i=0;i<nums.size();i++){
            int flag=0;
            sort(nums.begin(),nums.end());
            int k =0;
            int x = 0;
            while(k<nums.size()){
                if(nums[k]!=0){
                    x = nums[k];
                    break;
                }
                k++;
            }
            
            for(int j=0;j<nums.size();j++){
                if(nums[j]!=0){
                    flag=1;
                    nums[j] = nums[j]-x;
                }
            }
            if(flag==0){
              break;
            }
            ctr++;
            
        }
        return ctr;
    }
};