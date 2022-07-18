class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res(arr.size());
        if (arr.empty())
            return res;
        
        vector<int> temp = arr;
        
        sort(temp.begin(), temp.end());
        
        int key = 1;
        
        map<int,int> m;
        m[temp[0]] = key;
        
        for(int i=1; i<temp.size(); i++)
            if (temp[i] > temp[i-1])
                m[temp[i]] = ++key;
        
        for(int i=0; i<res.size(); i++)
            res[i] = m[arr[i]];
        
        return res; 
        
    }
};