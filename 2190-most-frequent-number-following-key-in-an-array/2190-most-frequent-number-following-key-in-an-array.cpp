class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int>m;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == key)
                m[nums[i+1]]++;
        }
        
        int max=0, res=1;
        for(auto i: m)
        {
            if(i.second > max)
            {
                max = i.second;
                res = i.first;
            }
        }
        return res;
    }
};