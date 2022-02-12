class Solution {
public:
    bool isvalid(string a, string b){
        int cnt = 0;
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i])cnt++;
        }
        return cnt == a.length()-1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        bool flag = true;
        set<string> st;
        for(auto &it: wordList){
            st.insert(it);
            if(it == endWord) flag = false;
        }
        if(flag) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int depth = 0;
        
        while(!q.empty()){
            depth++;
            int len = q.size();
            
            while(len--){
                string cur = q.front();
                q.pop();
                for(int i=0;i<cur.length();i++){
                    string temp = cur;
                    for(char c='a';c<='z';c++){
                        temp[i] = c;
                        if(cur.compare(temp)==0) continue;
                        if(temp.compare(endWord)==0) return depth+1;
                        if(st.find(temp) != st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};