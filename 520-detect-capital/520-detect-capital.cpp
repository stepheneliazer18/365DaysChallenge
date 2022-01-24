class Solution {
public:
    bool detectCapitalUse(string word) {
        string upper = word;
        string lower = word;
        string title = word;
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        title[0] = toupper(title[0]);
        if(upper == word || lower == word || title == word) return true;
        return false;
    }
};