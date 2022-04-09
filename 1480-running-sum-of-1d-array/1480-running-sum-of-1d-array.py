class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        a=[]
        sum=0
        for i in range(len(nums)):
            sum+=nums[i]
            a.append(sum)
#         print(a)
        return a