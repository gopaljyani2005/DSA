bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int vowel = 0;
        int i = 0;
        int size = s.size();
        while(i<k-1){
            if(isVowel(s[i])){
                vowel++;
            }
            i++;
        }
        while(i<size){
            if(isVowel(s[i])){
                vowel++;
            }
            ans = max(ans,vowel);
            if(isVowel(s[i-k+1])){
                vowel--;
            }
            i++;
        }
        return ans;
    }
};