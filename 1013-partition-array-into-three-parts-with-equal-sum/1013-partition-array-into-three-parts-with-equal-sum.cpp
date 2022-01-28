class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0) return false;
        
        int one_third = sum/3;
        cout<<"sum = "<<sum<<endl;
        cout<<one_third<<endl;
        
        int temp = 0;
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            cout<<"temp = "<<temp<<endl;
            if(temp == one_third){
                cnt++;
                temp = 0;
            }
        }
        cout<<"cnt = "<<cnt<<endl;
        return cnt>=3;
    }
};