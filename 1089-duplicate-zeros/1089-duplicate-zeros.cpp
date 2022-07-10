class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      vector<int>v;
        for(int i=0;i<arr.size();i++){
            v.push_back(arr[i]);
            if(arr[i]==0){
                v.push_back(arr[i]);
            }
                       
        }
         for(int i=0;i<arr.size();i++) {
             arr[i]=v[i];
         }             
    }
};
