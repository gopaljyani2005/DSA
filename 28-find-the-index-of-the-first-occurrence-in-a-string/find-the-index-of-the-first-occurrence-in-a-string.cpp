class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        vector<int> lps(size2, 0);
        int len = 0;
        int i = 1;
        while(i<size2){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;
        while(i<size1){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j==size2){
                    return i-size2;
                }
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};