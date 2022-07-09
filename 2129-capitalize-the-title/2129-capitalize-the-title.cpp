class Solution {
public:
    string capitalizeTitle(string title) {
        int i,j=1,n=title.length();
        
            title[i]=tolower(title[i]);
        for(i=0;i<=n;i=i+j+1)
        {
            j=0;
            while(title[i+j]!=' ' && title[i+j]!='\0')
            {title[i+j]=tolower(title[i+j]);
                j++;
            }
            
            if(j>2)
            title[i]=toupper(title[i]);
        }
        return title;
        
    }
};
