class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[numbers[i]] = i;
        
        for(int i=0;i<n;i++){
            int need = target - numbers[i];
            if(mp.find(need) != mp.end() && mp[need] != i) return {i+1,mp[need]+1};
        }
        
        return {0,1};
    }
};