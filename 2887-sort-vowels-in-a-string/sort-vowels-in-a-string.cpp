class Solution {
public:
    string sortVowels(string s) {
        string temp;
        int len = s.size();
        string t;
        for(int i=0;i<len;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                temp.push_back(s[i]);
                t.push_back(' ');
            }
            else{
                t.push_back(s[i]);
            }
        }
        sort(temp.begin(),temp.end());
        int ptr = 0;
        for(int i=0;i<len;i++){
            if(t[i] == ' '){
                t[i] = temp[ptr];
                ptr++;
            }
        }
        return t;
    }
};