class Solution {
public:
    int shipWithinDays(vector<int>& weights, int d) {
         int sum = 0;
    for(int i : weights)
        sum += i;
    
    int i = *max_element(weights.begin(), weights.end());
    int j = sum;
    int ans = INT_MAX;
    while(i <= j){
        int mid = (i+j)/2;
        int cnt = 1;
        int s = 0;
        for(int k = 0; k < weights.size(); k++){
            if(s+weights[k] > mid){
                cnt++;
                s = weights[k];
            }else{
                s += weights[k];
            }
        }
        // cout << mid << " " << cnt << endl;
        if(cnt <= d){
            ans = mid;
            j = mid-1;
        }else{
            i = mid+1;
        }
    }
    return ans;
    }
};