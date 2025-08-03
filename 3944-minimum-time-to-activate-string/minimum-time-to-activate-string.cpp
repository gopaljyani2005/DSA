long long funct(string s){
    long long size = s.size();
    long long ans = 0;
    long long l = 0;
    for(long long i=0;i<size;i++){
        if(s[i]=='*'){
            ans = ans + (i+1-l)*(size-i);
            l = i+1;
        }
    }
    return ans;
}

class Solution {
public:
    int minTime(string st, vector<int>& order, int k) {
        int n = st.size();
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            string temp = st;
            for(int i=0;i<=mid;i++){
                int index = order[i];
                temp[index] = '*';
            }
            long long ct = funct(temp);

            if(ct>=k){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans; 
    }
};