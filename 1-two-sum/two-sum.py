class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mymap = dict()
        size = len(nums)
        for i in range(0,size):
            if target-nums[i] in mymap:
                return [mymap[target-nums[i]],i]
            else:
                mymap[nums[i]] = i            
            
        