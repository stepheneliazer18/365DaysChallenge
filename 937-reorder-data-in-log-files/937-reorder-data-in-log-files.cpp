bool cmp(pair<string,string> p1, pair<string,string> p2){
    // if logs are equal we compare identifiers
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> vec1;
        vector<string> vec2;
        
        // we are taking letter logs into vec1
        // and digit logs into vec2 as we don't have to modify digit logs
        // we just have to sort letter logs and append the digit logs at the end
        
        for(auto &it: logs){
            string identifier, logs;
            
            int i = 0;
            int n = it.length();
            while(it[i] != ' ') identifier += it[i++];  // separating identifier and logs
            i++;
            while(i<n) logs += it[i++];
            
            if(isdigit(logs[0])) vec2.push_back(it);  // digit logs    
            else vec1.push_back({identifier,logs});   // letter logs
        }
              
        // sorting the letter logs using comparator function 
        sort(vec1.begin(),vec1.end(),cmp);
        
        vector<string> res;
        for(auto &it: vec1){
            res.push_back(it.first + " " +it.second);//storing the sorted letter logs into res 
        }
        for(auto &it: vec2) res.push_back(it); // appending the digit logs at the end of res
        
        return res;
    }
};