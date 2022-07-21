class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        set<pair<int,int>> st;
        st.insert({0,0});
        for(char c: path) {
            if(c=='N')
                x++;
            if(c=='S')
                x--;
            if(c=='E')
                y++;
            if(c=='W')
                y--;
            pair p(x,y);
            if(st.find(p)!=st.end())
                return true;
            else
                st.insert(p);
        }
        return false;
    }
};