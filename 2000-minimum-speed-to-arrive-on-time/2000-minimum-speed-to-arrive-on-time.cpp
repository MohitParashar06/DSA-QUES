class Solution {
public:

    bool check(vector<int>& dist, double hour, int mid){
        double val = 0;
        for(int i = 0; i < dist.size(); i++){
            if(i == dist.size()-1){
                val += (double)dist[i]/(mid*1.0);
            }
            else{
                val += ceil((double)dist[i]/(mid*1.0));
            }
        }
        // cout << mid << " " << val << endl;
        return val <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour < n-1) return -1;
        int i = 1, j = 1e9+1;
        int ans = -1;
        while(i < j){
            int mid = (i+j)/2;
            if(check(dist,hour,mid)){
                j = mid;
                ans = mid;
            }else{
                i = mid+1;
            }
        }
        return ans;
    }
};