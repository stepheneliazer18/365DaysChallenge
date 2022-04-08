class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        long long n = nums.size();
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        
        for(long long i=0;i<n;i++){
            long long sum = target - nums[i];
            long long l = i+1;
            long long r = n-1;
            while(l<r){
                if(nums[l]+nums[r] == sum){
                    long long z1 = 1,z2 = 1;
                    if(nums[l] == nums[r]){
                        int x = r-l+1;
                        cnt += (x*(x-1))/2;
                        l = r;
                        continue;
                    }
                    else{
                        while(l+1<r && nums[l] == nums[l+1]){
                            l++;
                            z1++;
                        }
                        while(r-1>l && nums[r] == nums[r-1]){
                            r--;
                            z2++;
                        }
                        cnt += z1*z2;
                    }

                }
                if(nums[l] + nums[r] < sum){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return cnt%1000000007;
    }
};