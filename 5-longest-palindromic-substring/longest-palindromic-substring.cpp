string funct(int index, string & s){
    int size = s.size();
    string right;
    right.push_back(s[index]);
    string left = "";
    int l = index-1;
    int r = index+1;
    while(l>=0 && r<size && s[l]==s[r]){
        left.push_back(s[l]);
        right.push_back(s[r]);
        l--;
        r++;
    }
    reverse(left.begin(), left.end());
    string ans1 = left + right;
    
    if(index>=1 && s[index]==s[index-1]){
        right  = "";
        left = "";
        right.push_back(s[index-1]);
        right.push_back(s[index]);
        l = index-2;
        r = index+1;
        while(l>=0 && r<size && s[l]==s[r]){
            left.push_back(s[l]);
            right.push_back(s[r]);
            l--;
            r++;
        }
        reverse(left.begin(), left.end());
        string ans2 = left + right;
        if(ans1.size()>ans2.size()){
            return ans1;
        }
        else{
            return ans2;
        }
    }
    else{
        return ans1;
    }
    
}

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int ans = 1;
        string str;
        str.push_back(s[0]);
        for(int i=1;i<size;i++){
            string tempstr = funct(i, s);
            if(tempstr.size()>ans){
                ans = tempstr.size();
                str = tempstr;
            }
        }
        return str;
    }
};