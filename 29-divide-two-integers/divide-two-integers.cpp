class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d1 = dividend;
        long long d2 = divisor;
        long long ans = d1/d2;
        if(ans<-pow(2,31)){
            return -pow(2,31);
        }
        else if(ans>pow(2,31)-1){
            return pow(2,31)-1;
        }
        else{
            return ans;
        }
    }
};