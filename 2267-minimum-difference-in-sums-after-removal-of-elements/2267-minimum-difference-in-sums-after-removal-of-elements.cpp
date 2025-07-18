class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        long long ls = 0, rs = 0, mini = LLONG_MAX;
        vector<long long> left(n), right(n);
        priority_queue<long long> pq1;
        priority_queue<long long , vector<long long>, greater<long long>> pq2;
        for(int i = 0; i < k; i++){
            pq1.push(nums[i]);
            ls += nums[i];
        }
        left[k-1] = ls;
        for(int i = k; i < n-k; i++){
            if(!pq1.empty() && nums[i] < pq1.top()){
                ls += nums[i]-pq1.top();
                pq1.pop();
                pq1.push(nums[i]);
            }
            left[i]=ls;
        }

        for(int i = n-1; i >= n-k; i--){
            rs += nums[i];
            pq2.push(nums[i]);
        }
        right[n-k]=rs;
        for(int i = n-k-1; i >= k-1; i--){
            if(!pq2.empty() && nums[i] > pq2.top()){
                rs += nums[i]-pq2.top();
                pq2.pop();
                pq2.push(nums[i]);
            }
            right[i] = rs;
        }

        for(int i = k-1; i < n-k; i++){
            mini = min(mini,left[i]-right[i+1]);
        }
        return mini;
    }
};