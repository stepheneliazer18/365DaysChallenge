class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> records(101, 0);
        int res = 0, year = 0;
        for(int i = 0; i < logs.size(); i++) {
            records[logs[i][0] - 1950]++;
            records[logs[i][1] - 1950]--;
        }
        for(int i = 0; i <= 100; i++) {
            if(i != 0) records[i] += records[i - 1];
            if(records[i] > res) {
                res = records[i];
                year = i + 1950;
            }
        }
        return year;
    }
};