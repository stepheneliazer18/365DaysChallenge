class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split()
        print(l)
        
        if(len(l) != len(pattern)): return False
        
        dic = defaultdict(int)
        fic = defaultdict(int)
        for i,n in enumerate(l):
            
            if(dic.get(pattern[i],0) == 0):
                print(n, n in dic.values())
                if (n in dic.values()) == False:
                    dic[pattern[i]] = n
                    print("in")
                    fic[n] = pattern[i]
                else: return False
            elif(dic[pattern[i]] != n):
                return False
            print(dic.values)
        return True