class Solution {
public:
    int totalMoney(int n) {
        int w = n/7;
        int r = n%7;

        int ans = 28*w + 7*(w*(w-1))/2 + w*r + (r*(r+1))/2;
        return ans;
    }
};