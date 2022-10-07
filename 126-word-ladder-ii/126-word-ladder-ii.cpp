class Solution {
private:
    void bfs(string beginWord, string endWord, vector<string>& wordList, set<string>& st, map<string,int>& mp){
        int len = beginWord.length();
        
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            
            if(word == endWord) return;
            
            int steps = mp[word];
            for(int i=0;i<len;i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
    }
    void dfs(string word, vector<string> vec, string beginWord, set<string>& st, map<string,int>& mp, vector<vector<string>>& ans){
        int len = word.length();
        
        if(word == beginWord){
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            
            return;
        }
        
        int steps = mp[word];
        for(int i=0;i<len;i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    vec.push_back(word);
                    dfs(word, vec, beginWord, st, mp, ans);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        map<string,int> mp;
        set<string> st(wordList.begin(),wordList.end());
        
        bfs(beginWord, endWord, wordList, st, mp);

        vector<vector<string>> ans;
        vector<string> vec;
        vec.push_back(endWord);
        dfs(endWord, vec, beginWord, st, mp, ans);
        
        return ans;
    }
};