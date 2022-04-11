class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        l = []
        for i in grid:
            for j in i:
                l.append(j)
        print(l)
        
        k = k % len(l)
        
        print(len(l)-k)
        
        l = l[len(l)-k:] + l[:len(l)-k]
        
        print(l)
        
        ans = []
        x = 0
        for i in range(len(grid)):
            temp = []
            for j in range(len(grid[i])):
                temp.append(l[x])
                x+=1
            ans.append(temp)
        return ans