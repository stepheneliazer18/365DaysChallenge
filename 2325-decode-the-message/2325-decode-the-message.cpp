class Solution {
public:
     string decodeMessage(string key, string message) {
        unordered_map<char,char>a;
        int m=97;
        string s="";
        for(int i=0;i<key.size();i++)
        {  char z=key[i];
            
           if(a.find(z)==a.end()&&z!=' ')
           {
               a[z]=m;
                m++;
               
           }          
           
            
        }
        for(int i=0;i<message.size();i++)
        {  if(message[i]==' ')
          {
            s+=' ';
          }
         else{
                         s+=a[message[i]];

          }
        }
        
    return s;
    }
};