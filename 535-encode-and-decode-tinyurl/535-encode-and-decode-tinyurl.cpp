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
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(ls.count(longUrl)) return ls[longUrl];
        string cod = tinyCode();
        while(sl.count(cod)) cod = tinyCode();
        ls[longUrl] = cod;
        sl[cod] = longUrl;
     return cod;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return sl[shortUrl];
    }
};
/*
if(find helpful) {
 do upvote(); // thanks:)
 }
 */
