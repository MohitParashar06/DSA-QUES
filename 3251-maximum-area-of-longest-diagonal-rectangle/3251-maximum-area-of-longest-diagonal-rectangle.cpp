class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        double dig = 0.0;
        for (int i = 0; i < dimensions.size(); i++) {
            int len = dimensions[i][0];
            int wid = dimensions[i][1];
            double val = sqrt(len * len * 1.0 + wid * wid * 1.0);
            if (val >= dig) {
                if (val == dig) {
                    area = max(area, len * wid);
                } else {
                    area = len * wid;
                }
                dig = val;
            }
        }
        return area;
    }
};