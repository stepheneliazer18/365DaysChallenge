class Solution:
    def maximumWealth(self, a: List[List[int]]) -> int:
        maxi=sum(a[0])
        for i in a:
            maxi=max(sum(i),maxi)
        return maxi