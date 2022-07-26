class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.rbegin(), amount.rend());
        int res = 0;
        while(amount[0] > 0)
        {
            ++res;
            if(amount[0]>0)
            {
                amount[0]--;
            }
            if(amount[1]>0)
            {
                amount[1]--;
            }
            
            sort(amount.rbegin(), amount.rend());
        }
        
        return res;
    }
};