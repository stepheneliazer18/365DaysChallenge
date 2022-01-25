class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]==arr[i] || arr[i]==arr[i+1] ||
                arr[i-1]>arr[i] && arr[i]<arr[i+1])return false;
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) cnt++;
        }
        return cnt==1;
    }
};