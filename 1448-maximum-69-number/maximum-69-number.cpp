class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digit;
        while(num!=0){
            digit.push_back(num%10);
            num = num/10;
        }
        reverse(digit.begin(),digit.end());
        int ans = 0;
        bool check = true;
        for(int i=0;i<digit.size();i++){
            if(digit[i]==9){
                ans = ans + 9 * pow(10, digit.size()-1-i);
            }
            else if(check){
                ans = ans + 9 * pow(10, digit.size()-1-i);
                check = false;
            }
            else{
                ans = ans + 6 * pow(10, digit.size()-1-i);
            }
        }
        return ans;
    }
};