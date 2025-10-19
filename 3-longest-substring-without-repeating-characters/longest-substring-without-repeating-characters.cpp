class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, bool> map;
        while(r<size){
            if(!map[s[r]]){
                ans = max(ans, r-l+1);
            }
            else{
                while(map[s[r]]){
                    map[s[l]] = false;
                    l++;
                }
                ans = max(ans, r-l+1);
            }
            map[s[r]] = true;
            r++;
        }
        return ans;
    }
};