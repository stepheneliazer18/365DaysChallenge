class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int>hash(1001,0);
        for(int i=0;i<n;i++)
            hash[arr1[i]]++;
        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            while(hash[arr2[i]])
            {
                ans.push_back(arr2[i]);
                hash[arr2[i]]--;
            }
        }
        for(int i=0;i<1001;i++)
        {
            while(hash[i])
            {
                ans.push_back(i);
                hash[i]--;
            }
        }
        return ans;
    }
};