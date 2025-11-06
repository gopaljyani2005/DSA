class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        int size1 = s.size();
        int size2 = t.size();
        if(size1 != size2){
            return false;
        }
        for(int i=0;i<size1;i++){
            map[s[i]]++;
        }    

        for(int i = 0;i<size2;i++){
            if(map[t[i]]){
                map[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};