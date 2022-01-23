class Solution {
public:
    int len(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num/=10;
        }
        return cnt;
    }
    int CreateNum(int start, int len){
        int x = start;
        int num = 0;
        for(int i=1;i<=len;i++){
            num = (num*10) + x;
            x++;
        }
        return num;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        int low_len = len(low);
        int max_len = len(high);

        int start_digit = low/(pow(10,low_len-1));
        int num = CreateNum(start_digit, low_len);

        if(low>num) start_digit++;

        int len = low_len;
        while(len<=max_len){
            for(int i=start_digit;i<=10-len;i++){
                int num = CreateNum(i,len);
                if(num>high) break;
                res.push_back(num);
            }
            len++;
            start_digit = 1;
        }
        return res;
    }
};