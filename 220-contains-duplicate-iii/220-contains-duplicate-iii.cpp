class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        int n = nums.size();
        if(n==1) return false;
        
        vector<pair<long long int,int>>vec;
        
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(vec[i].first-vec[j].first)<=t){
                    if(abs(vec[i].second-vec[j].second)<=k)return true;
                }
                else{
                    break;
                }

            }
        }
        return false;
    }
};
