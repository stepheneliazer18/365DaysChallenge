class Solution {
public:
    struct{
        bool operator()(vector<int> v1, vector<int> v2){
            return v1[1] > v2[1];
        }
    }cmp;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        
        for(auto &it: boxTypes){
            for(auto &it1: it)cout<<it1<<" ";
            cout<<endl;
        }
        
        int n = boxTypes.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if(truckSize<=0)break;
            if(boxTypes[i][0]>truckSize){
                res += truckSize * boxTypes[i][1];
                truckSize = 0;
                break;
            }
            else{
                res += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        return res;
    }
};