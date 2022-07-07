class Solution {
public:
    int countAsterisks(string s) {
        int count = 0 , count1=0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '|') count1++;
            if(count1%2 == 0){
                  if(s[i] == '*') count++ ;
            }
        }
        return count;
    }
};
