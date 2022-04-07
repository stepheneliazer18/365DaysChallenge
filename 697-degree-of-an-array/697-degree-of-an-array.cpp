class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        
        map<int,vector<int>> mp;
        
        
        int len = 1;
        int deg = 1;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            if(mp.find(ele) == mp.end()){
                cout<<ele<<endl;
                vector<int> vec{i,1};
                mp[ele] = vec;
            }
            else{
                int ind = mp[ele][0];
                mp[ele][1]++;
                cout<<mp[ele][0]<<" "<<mp[ele][1]<<endl;
                cout<<deg<<endl;
                if(mp[ele][1] > deg){
                    len = i-ind+1;
                    deg = mp[ele][1];
                }
                else if(mp[ele][1] == deg) len = min(len,i-ind+1);
            }
        }
        // for(auto &it: mp){
        //     cout<<it.first<<" -> "<<it.second[0]<<" "<<it.second[1]<<endl;
        // }
        return len;
    }
};