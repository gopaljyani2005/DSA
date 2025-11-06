bool patternMatch(string str, string pattern){
    int n = str.size();
    int m = pattern.size();
    vector<int> table(m, 0);
    int len = 0;
    int i = 1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            table[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = table[len-1];
            }
            else{
                table[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;
    while(i<n){
        if(pattern[j]==str[i]){
            i++;
            j++;
            if(j==m){
                return true;
            }
        }
        else{
            if(j!=0){
                j = table[j-1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int it = (m+n-1)/n;
        cout<<it<<endl;
        string str = "";
        for(int i=0;i<it;i++){
            str+=a;
        }
        bool caseone = patternMatch(str, b);
        if(caseone == true){
            return it;
        }
        str+=a;
        bool casetwo = patternMatch(str, b);
        if(casetwo == true){
            return it + 1;
        }
        return -1;
    }
};