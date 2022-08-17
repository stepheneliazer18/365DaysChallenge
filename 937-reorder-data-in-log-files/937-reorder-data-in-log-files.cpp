bool cmp(pair<string,string> p1, pair<string,string> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}
class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> vec1;
        vector<string> vec2;
        
        for(auto &it: logs){
            string identifier, logs;
            
            int i = 0;
            int n = it.length();
            while(it[i] != ' ') identifier += it[i++];
            i++;
            while(i<n) logs += it[i++];
            
            if(isdigit(logs[0])) vec2.push_back(it);
            else vec1.push_back({logs,identifier});
        }
                
        sort(vec1.begin(),vec1.end(),cmp);
        
        vector<string> res;
        for(auto &it: vec1){
            res.push_back(it.second + " " + it.first);
        }
        for(auto &it: vec2) res.push_back(it);
        
        return res;
    }
};