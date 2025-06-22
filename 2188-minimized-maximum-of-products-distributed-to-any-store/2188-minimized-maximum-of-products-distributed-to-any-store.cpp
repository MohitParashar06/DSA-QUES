class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        int ans = 0;
        int j = *max_element(quant.begin(), quant.end());
        int i = 1;
        while(i <= j){
            int mid = (i+j)/2;
            auto temp = quant;
            int k = 0;
            int d = n;
            while(k < quant.size() && d--){
                if(temp[k] <= mid){
                    temp[k] = 0;
                    k++;
                }
                else{
                    temp[k] -= mid;
                }
            }
            if(k < quant.size()){
                i = mid+1;
            }else{
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }
};