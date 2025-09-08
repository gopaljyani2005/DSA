bool funct(int temp1, int temp2){
    while(temp1){
        int r = temp1%10;
        if(r==0){
            return false;
        }
        temp1 = temp1/10;
    }

    while(temp2){
        int r = temp2%10;
        if(r==0){
            return false;
        }
        temp2 = temp2/10;
    }
    return true;
}
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for(int i=1;i<n;i++){
            bool check = funct(i,n-i);
            if(check){
                return {i,n-i};
            }
        }
        return ans;
    }
};