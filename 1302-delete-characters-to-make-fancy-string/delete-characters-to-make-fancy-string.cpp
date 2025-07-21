class Solution {
public:
    string makeFancyString(string s) {
        int size = s.size();
        string ans = "";
        int ct = 0;
        char ch = s[0];
        ans.push_back(s[0]);
        ct++;
        for(int i=1;i<size;i++){
            if(s[i]==ch && ct<2){
                ans.push_back(ch);
                ct++;
            }
            else if(s[i]==ch){
                continue;
            }
            else{
                ch = s[i];
                ans.push_back(ch);
                ct = 1;
            }
        }
        return ans;
    }
};