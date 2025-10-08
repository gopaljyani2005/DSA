class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int u = intervals[0][0];
        int v = intervals[0][1];

        for(int i=1;i<size;i++){
            if(intervals[i][0]>v){
                ans.push_back({u,v});
                u = intervals[i][0];
                v = intervals[i][1];
            }
            else{
                v = max(v,intervals[i][1]);
            }
        }
        ans.push_back({u,v});
        return ans;
    }
};