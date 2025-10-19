class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        ans = 1
        answer = s[0]
        for i in range(0,size):
            l = i
            r = i
            while l>=0 and r < size and s[l] == s[r]:
                l = l-1
                r = r+1
            ans = max(ans,r-l-1)
            if ans > len(answer):
                answer = s[l+1:r]

            l = i-1
            r = i
            while l>=0 and r < size and s[l] == s[r]:
                l = l-1
                r = r+1

            ans = max(ans,r-l-1)
            if ans > len(answer):
                answer = s[l+1:r]
        print(ans)
        return answer


        