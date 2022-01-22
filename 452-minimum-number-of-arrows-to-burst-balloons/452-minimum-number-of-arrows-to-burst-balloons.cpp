class Solution {
public:
    struct{
        bool operator()(vector<int>& v1, vector<int>& v2)const{
            return v1[1] < v2[1];
        }
    }cmp;
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        
        int maxi = 1;
        int prev = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>prev){
                maxi++;
                prev = points[i][1];
            }
        }
        return maxi;
    }
};