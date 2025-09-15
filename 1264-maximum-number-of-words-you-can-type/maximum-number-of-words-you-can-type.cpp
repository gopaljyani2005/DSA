class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       unordered_map<char,bool> map;
        int size = brokenLetters.size();
        for(int i=0;i<size;i++){
            map[brokenLetters[i]] = true;
        }

        size = text.size();
        bool b = true;
        int ans = 0;
        for(int i=0;i<size;i++){
            if(text[i]==' '){
                if(b==true){
                    ans++;
                }
                b = true;
            }
            else if(b){
                if(map[text[i]]){
                    b=false;
                }
            }
        }
        if(b){
            return ans+1;
        }
        else{
            return ans;
        }
    }
};