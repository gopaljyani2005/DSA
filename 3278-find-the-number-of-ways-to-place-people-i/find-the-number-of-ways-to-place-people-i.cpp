class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int size = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) 
        return a[1] > b[1];
    return a[0] < b[0];
});

        int ct = 0;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(!(x1<=x2 && y2<=y1)){
                    cout<<"here "<<i<<j<<endl;
                    continue;
                }
                bool b = true;
                for(int k=0;k<size;k++){
                    if(k==i || k==j){
                        continue;
                    }
                    else{
                        int x = points[k][0];
                        int y = points[k][1];
                        if((x1<=x && x<=x2) &&(y2<=y && y<=y1)){
                            b = false;
                            cout<<i<<j<<endl;                            
                            break;
                        }
                    }
                }
                if(b == true){
                    ct++;
                }
            }
        }
        return ct;
    }
};