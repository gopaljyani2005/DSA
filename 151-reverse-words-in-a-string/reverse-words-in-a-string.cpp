class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int ptr = 0;
        stack<string> st;
        string ans = "";

        while(ptr<size){
            while(ptr<size && s[ptr]==' '){
                ptr++;
            }
            string temp = "";
            while(ptr<size && s[ptr] !=' '){
                temp.push_back(s[ptr]);
                ptr++;
            }
            if(temp.size())
            st.push(temp);
        }
        while(st.size()>1){
            ans = ans + st.top();
            st.pop();
            ans = ans + " ";
        }
        ans+=st.top();
        return ans;
    }
};