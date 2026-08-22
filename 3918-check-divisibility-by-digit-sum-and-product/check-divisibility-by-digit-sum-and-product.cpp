class Solution {
public:
    bool checkDivisibility(int n) {
       int val = 0;
       int sum = 0;
       int prod = 1;

       int temp = n;
       while(temp){
        int r = temp%10;
        temp = temp/10;
        sum+=r;
        prod*=r;
       }

       return n%(sum+prod)==0; 
    }
};