class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int total = 1;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            total *= i;
        }
        
        string ans;
        k--;
        for(int i=0;i<n;i++){
            int size = total/nums.size();
            int ind = k/size;
            ans += (nums[ind] + '0');
            nums.erase(nums.begin() + ind);
            k = k % size;
            total = size;
        }
        
        return ans;
    }
};