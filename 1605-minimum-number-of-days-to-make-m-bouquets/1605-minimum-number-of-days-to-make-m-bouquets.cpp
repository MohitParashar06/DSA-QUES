class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        long long n = (long long)m*(long long)k;
        if(n > (long long)bd.size()) return -1;
        if(n == (long long)bd.size()) return *max_element(bd.begin(), bd.end());

        int j = *max_element(bd.begin(), bd.end());
        int i = 1;
        int ans = 0;
        while(i <= j){
            int mid = (i+j)/2;
            int cnt = 0, m_cnt = 0;
            for(int it = 0; it < bd.size(); it++){
                if(bd[it] <= mid) cnt++;
                else{
                    cnt = 0;
                }
                if(cnt == k){
                    cnt = 0;
                    m_cnt++;
                }
            }
            if(m_cnt >= m){
                ans = mid;
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return ans;
    }
};