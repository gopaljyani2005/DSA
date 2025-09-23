int funct(string s){
    int size = s.size();
    int a = 0;
    for(int i=size-1;i>=0;i--){
        a = a + pow(10,size-1-i)*(s[i]-'0');
    }
    return a;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();

        vector<string> temp1;
        vector<string> temp2;
        string temp;
        for(int i=0;i<size1;i++){
            if(version1[i]=='.'){
                temp1.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(version1[i]);
            }
        }
        temp1.push_back(temp);
        temp.clear();

        for(int i=0;i<size2;i++){
            if(version2[i]=='.'){
                temp2.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(version2[i]);
            }
        }
        temp2.push_back(temp);
        temp.clear();


        int ele1 = temp1.size();
        int ele2 = temp2.size();
        if(ele1 != ele2){
            if(ele1<ele2){
                for(int i=ele1;i<ele2;i++){
                    temp1.push_back("0");
                }
            }
            else{
                for(int i=ele2;i<ele1;i++){
                    temp2.push_back("0");
                }
            }
        }
            for(int i=0;i<max(ele1,ele2);i++){
                int a = funct(temp1[i]);
                int b = funct(temp2[i]);
                cout<<a<<" "<<b<<endl;
                if(a<b){
                    return -1;
                }
                else if(a>b){
                    return 1;
                }
                else{
                    continue;
                }
            }
        
        return 0;
    }
};