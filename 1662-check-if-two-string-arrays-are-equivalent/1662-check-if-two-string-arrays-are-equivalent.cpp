class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2){
        string forW1 = "";
        string forW2 = "";
        for (int i = 0; i < word1.size(); i++)
        {
            string tmp = word1[i];
            forW1 += tmp;
        }
        for (int i = 0; i < word2.size(); i++)
        {
            string tmp = word2[i];
            forW2 += tmp;
        }
        return forW1 == forW2;
    }
};