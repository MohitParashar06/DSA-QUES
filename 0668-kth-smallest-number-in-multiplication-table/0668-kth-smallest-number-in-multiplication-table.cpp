class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int i = 1,  j = m*n;
        int ans = 0;
        while(i <= j){
            int mid = (i+j)/2;

            int cnt =0 ;
            for(int l = 1; l <= m; l++){
                cnt += min(n,mid/l);
            }
            if(cnt < k) i = mid+1;
            else j = mid-1;
        }
        return i;
    }
};