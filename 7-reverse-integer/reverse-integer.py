class Solution:
    def reverse(self, x: int) -> int:
        if x >0 :
            nums1 = []
            nums2 = []

            temp1 = x
            temp2 = pow(2,31)-1

            while temp1 > 0:
                r = temp1%10
                temp1 = int(temp1/10)
                nums1.append(r)

            while temp2 > 0:
                r = temp2%10
                temp2 = int(temp2/10)
                nums2.append(r)
            nums2.reverse()

            size = min(len(nums1), len(nums2))

            for i in range(size):
                if nums1[i]<nums2[i]:
                    break
                elif nums1[i]>nums2[i] and len(nums1)==len(nums2):
                    return 0           

            size = len(nums1)
            ans = 0
            for i in range(size):
                ans = ans + nums1[i]*pow(10,size-1-i)

            return ans

        elif x==0:
            return x

        else:
            nums1 = []
            nums2 = []

            temp1 = x
            temp2 = -pow(2,31)

            while temp1 != 0:
                r = temp1%10
                temp1 = int(temp1/10)
                if r == 0 :
                    nums1.append(r)
                else:
                    nums1.append(10-r)
            print(nums1)
            while temp2 != 0:
                r = temp2%10
                temp2 = int(temp2/10)
                if r == 0:
                    nums2.append(0)
                else :
                    nums2.append(10-r)
            nums2.reverse()
            print(nums2)

            size = min(len(nums1), len(nums2))

            for i in range(size):
                if nums1[i]<nums2[i]:
                    break
                elif nums1[i]>nums2[i] and len(nums1)==len(nums2):
                    return 0           

            size = len(nums1)
            ans = 0
            for i in range(size):
                ans = ans - (nums1[i])*pow(10,size-1-i)

            return ans                