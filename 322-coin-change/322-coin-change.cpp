//This is not normal denomination
//Hence Greey doesn't work 
//only dp works
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(),coins.end(),greater<int>());
//         int cnt = 0;
//         for(auto &it: coins){
//             if(amount>0 && it<=amount){
//                 int coin = amount/it;
//                 cnt += amount/it;
//                 amount -= coin*it;
//             }
//             cout<<"coins = "<<cnt<<endl;
//             cout<<"num = "<<it<<endl;
//             cout<<"amount = "<<amount<<endl;
//         }
//         return amount==0?cnt:-1;
//     }
// };
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int m = amount;

        vector<vector<int>> res(n+1,vector<int>(m+1));

        for(int i=0;i<=m;i++){
            res[0][i] = 10001;
        }
        for(int i=0;i<=n;i++){
            res[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j) res[i][j] = min(res[i-1][j],res[i][j-coins[i-1]]+1);
                else res[i][j] = res[i-1][j];
            }
        }

        if(res[n][m]>10000) return -1;
        return res[n][m];
    }
};