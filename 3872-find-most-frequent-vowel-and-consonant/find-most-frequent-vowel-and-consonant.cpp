class Solution {
public:
    int maxFreqSum(string s) {
        int maxi1 = 0;
        int maxi2 = 0;
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                map[s[i]]++;
                maxi1 = max(maxi1,map[s[i]]);
            }
            else{
                map[s[i]]++;
                maxi2 = max(maxi2, map[s[i]]);
            }
        }
        return maxi1 + maxi2;
    }
};