class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp1;
        map<int,int> mp2;
        
        int n = nums1.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp1[nums1[i]+nums2[j]]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        
        for(auto &it: mp1) cout<<it.first<<" "<<it.second<<endl;
        cout<<" ------- "<<endl;
        for(auto &it: mp2) cout<<it.first<<" "<<it.second<<endl;
        cout<<" ------- "<<endl;
        
        int res = 0;
        for(auto &it: mp1){
            if(mp2.find(-1*(it.first)) != mp2.end()){
                res += it.second * mp2[-1*(it.first)];
            }
        }
        
        return res;
    }
};