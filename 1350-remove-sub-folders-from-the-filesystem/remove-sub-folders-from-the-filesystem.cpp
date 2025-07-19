class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_map<string,bool> map;
        vector<string> ans;
        int size = folder.size();
        for(int i=0;i<size;i++){
            int size1 = folder[i].size();
            string temp = folder[i];
            string temp2 = "";
            bool flag = true;
            for(int j=0;j<size1;){
                temp2.push_back('/');
                j++;
                while(j<size1 && temp[j]!='/'){
                    temp2.push_back(folder[i][j]);
                    j++;}
                cout<<temp2<<endl;
                if(map[temp2]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                map[folder[i]] = true;
                ans.push_back(folder[i]);
            }
        }
        return  ans;
    }
};