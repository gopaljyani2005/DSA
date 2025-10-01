class Solution {
public:
    int numWaterBottles(int numBottles, int e) {
        int ans = numBottles;
        int filled = numBottles;
        while(filled>=e){
            int temp = filled/e;
            ans = ans + temp;
            filled = filled-temp*e + temp;
        }
        return ans;
    }
};