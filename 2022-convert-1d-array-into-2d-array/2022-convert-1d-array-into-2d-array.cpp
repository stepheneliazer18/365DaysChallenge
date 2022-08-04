class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if(m*n!=original.size())
            return res;
        
        vector<int> t;
        for(int k=0;k<original.size();k++)
        {
            t.push_back(original[k]);
            if(t.size()==n)
            {
                res.push_back(t);
                t.clear();
            }
        }
        return res;
    }
};