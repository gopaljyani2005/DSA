class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        di = dict()
        l = len(nums)
        for i in range(0,l):
            di[nums[i]] = True

        result = 0
        ptr = k
        while result == 0:
            if ptr not in di:
                result = ptr
            print(ptr)    
            ptr = ptr + k
        return result            