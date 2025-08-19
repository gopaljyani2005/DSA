class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        int e = 0;
        int size = s.size();
        for(int i=1;i<size;i++){
            if(s[i]-s[i-1] == 1){
                e++;
            }
            else{
                ans = max(ans,e);
                e = 0;
            }
        }
        ans = max(ans,e);
        return ans + 1;
    }
};