class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (equal(begin(suits)+1, end(suits), begin(suits)))
            return "Flush";
        int cnt[14] = {0};
        for (int& r: ranks)
            cnt[r]++;
        int mx = *max_element(begin(cnt), end(cnt));
        if (mx >= 3)
            return "Three of a Kind";
        return mx == 2 ? "Pair" : "High Card";
    }
};