class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, int> mp;
        
        for(int i=0; i<rectangles.size(); i++){
            mp[(double)rectangles[i][0]/rectangles[i][1]]++;
        }
        
        long long res = 0;
        
        for(auto x:mp){
            res+=((long long)(x.second-1)*x.second)/2;
        }
        return res;
    }
};