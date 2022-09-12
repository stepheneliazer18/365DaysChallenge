class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        int total = 1;
        for(int i=n;i>=1;i--) total *= i;
        
        string ans;
        int size = n;
        k--;
        for(int i=0;i<n;i++){
            size = total/nums.size();
            int ind = k/size;
            ans += (nums[ind] + '0');
            nums.erase(nums.begin() + ind);
            k = k % size;
            total = size;
        }
        
        return ans;
    }
};