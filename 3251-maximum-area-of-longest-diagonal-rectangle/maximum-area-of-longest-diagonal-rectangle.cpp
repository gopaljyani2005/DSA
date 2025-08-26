class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        double dia = 0;
        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            double tempdia = sqrt(l*l + w*w);
            if(tempdia>dia){
                area = l*w;
                dia = tempdia;
            }
            else if(tempdia == dia){
                area = max(area, l*w);
            }
        }
        return area;
    }
};