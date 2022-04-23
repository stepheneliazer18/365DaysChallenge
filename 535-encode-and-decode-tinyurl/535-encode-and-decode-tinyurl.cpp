class Solution {
public:
    unordered_map<string, string> ls, sl;
    string tinyCode() {
        string res = "";
        string c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        for(int i=0; i<6; i++) 
            res += c[rand() % 62];
     return "http://tinyUrl.com/"+res;
    }
    string encode(string longUrl) {
        if(ls.count(longUrl)) return ls[longUrl];
        string cod = tinyCode();
        while(sl.count(cod)) cod = tinyCode();
        ls[longUrl] = cod;
        sl[cod] = longUrl;
     return cod;
    }

    string decode(string shortUrl) {
        return sl[shortUrl];
    }
};