import sys
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        maxe = -sys.maxsize-1
        mine = +sys.maxsize

        maxi = 0
        mini = 0

        size = len(nums)

        for i in range(0,size):
            if nums[i]<mine:
                mine = nums[i]
                mini = i

            if nums[i]>maxe:
                maxe = nums[i]
                maxi = i

        a = max(mini, maxi) + 1
        b = size - min(mini, maxi)
        c = min(mini, maxi) +1  + size - max(mini, maxi)
        return min(a,min(b,c))    