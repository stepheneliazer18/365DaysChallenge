class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        d = {}
        d[p[0]] = 1
        l = 1
        for i in range(1,len(p)):
            if(p[i] == 'a' and p[i-1] == 'z' or p[i] == chr(ord(p[i-1])+1)):
                l += 1
            else:
                l = 1
                
            if(p[i] in d.keys()):
                d[p[i]] = max(l,d[p[i]])
            else:
                d[p[i]] = l
                
        ans = 0
        for i in d.values():
            print(i)
            ans += i
        return ans