class Solution:
    def simplifyPath(self, path: str) -> str:
        i = 0
        s = ''
        while(i<len(path)):
            if path[i]=='/':
                s+='/'
                while (i<len(path)):
                    if path[i]!='/':
                        break
                    i+=1
            else:
                s+=path[i]
                i+=1
        l = s.split('/')
        if l[-1]=="": l.pop()
        res = []
        for i in range(len(l)):
            if l[i]=='.':
                continue
            if l[i]=="..":
                if res[-1]!="":res.pop()
            else: res.append(l[i])
            print(res)
        return "/"+"/".join(res[1:])