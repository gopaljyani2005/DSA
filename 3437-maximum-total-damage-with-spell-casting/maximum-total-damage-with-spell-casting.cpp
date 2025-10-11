long long funct(int index, int size, vector<int> & power, vector<long long > & dp){
    if(index>=size){
        return 0;
    }
    else if(dp[index]!=-1){
        return dp[index];
    }
    else{
        long long take = 0;
        long long nottake = 0;
        // here is solve this first case if we want to take this index and equal element 
        for(int i=index;i<size;i++){
            if(power[index]==power[i]){
                take+=power[index];
            }
            else if(power[i]-power[index]>2){
                take = take + funct(i, size, power, dp);
                break;
            }
            else{
                continue;
            }
        }


        // /here is solve this case where this index element and equal to this is not take in this case 
        for(int i=index+1;i<size;i++){
            if(power[index]==power[i]){
                continue;
            }
            else{
                nottake = funct(i, size, power, dp);
                break;
            }
        }

        dp[index] = max(take, nottake);
        return dp[index];
    }
}


class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int size = power.size();
        vector<long long> dp(size, -1);

        return funct(0, size, power, dp);
    }
};