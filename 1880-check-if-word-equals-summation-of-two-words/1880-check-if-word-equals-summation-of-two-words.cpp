class Solution {
public:
    int sum(string s){
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum=sum*10+(int(s[i]-'a'));
        }
        return sum;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int x= sum(firstWord);
        int y= sum(secondWord);
        int z= sum(targetWord);
        
        return x+y==z ? 1:0;
    }
};