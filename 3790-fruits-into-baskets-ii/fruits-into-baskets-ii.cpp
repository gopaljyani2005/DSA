class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int size = fruits.size();
        vector<bool> visited(size,false);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(visited[j]==false && baskets[j]>=fruits[i]){
                    visited[j] = true;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<size;i++){
            if(visited[i]==false){
                ans++;
            }
        }
        return ans;
    }
};