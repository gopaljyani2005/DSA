class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> temp(size,0);
        int i = size-1;
        int maxi = INT_MIN;
        while(i>=0){
            maxi = max(maxi, prices[i]);
            temp[i] = maxi;
            i--;
        }
        maxi = 0;
        for(int i=0;i<size;i++){
            maxi = max(maxi, temp[i]-prices[i]);
        }
        return maxi;
    }
};