int funct(int i, int j, int k , vector<vector<double>> & p){
    return abs((p[k][1]-p[i][1])- (((p[i][1]-p[j][1])/(p[i][0]-p[j][0]))*(p[k][0]-p[i][0])))<=1e-6;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        vector<vector<double>> p;
        unordered_map<int,int> map;
        for(int i=0;i<size;i++){
            double a = points[i][0];
            double b = points[i][1];
            p.push_back({a,b});
        }


        int ans = min(size,2);
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int ct = 2;
                for(int k=j+1;k<size;k++){
                    if(p[i][0]!=p[j][0]){
                        bool check = funct(i,j,k,p);
                        if(check){
                            ct = ct+1;
                            ans = max(ans,ct);
                        }
                        }
                }
            }
        }

        for(int i=0;i<size;i++){
            map[points[i][0]]++;
            ans = max(ans, map[points[i][0]]);
        }
        return ans;
    }
};