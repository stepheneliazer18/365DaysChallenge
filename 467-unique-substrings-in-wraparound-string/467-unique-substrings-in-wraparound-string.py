class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        d = defaultdict(int)
        d[p[0]] = 1
        l = 1
        for i in range(1,len(p)):
            if(p[i] == 'a' and p[i-1] == 'z' or p[i] == chr(ord(p[i-1])+1)):
                l += 1
            else:
                l = 1
            d[p[i]] = max(l,d[p[i]])
                
        return sum(d.values())