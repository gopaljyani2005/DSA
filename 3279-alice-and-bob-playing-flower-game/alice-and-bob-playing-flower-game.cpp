class Solution {
public:
    long long flowerGame(int n, int m) {
        long long e1 = n/2;
        long long e2 = m/2;
        long long o1,o2;
        if(n%2==0){
            o1 = e1;
        }
        else{
            o1 = e1+1;
        }

        if(m%2==0){
            o2 = e2;
        }
        else{
            o2 = e2 + 1;
        }

        return e1*o2 + e2*o1;
    }
};