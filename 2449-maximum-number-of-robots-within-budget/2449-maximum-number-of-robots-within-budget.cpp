class Solution {
public:

    bool f(int k, vector<int>& ct, vector<int>& rc, long long budget){
        int i;
        long long sum = 0;
        long long maxi = -1;
        priority_queue<pair<int,int>> pq;
        for(i=0; i < k; i++){
            sum += rc[i];
            pq.push({ct[i],i});
        }
        if((long long)(pq.top().first + k*sum) <= budget) return 1;
        int j = 0;
        while(i < ct.size()){
            sum += rc[i];
            sum -= rc[j++];
            pq.push({ct[i],i});
            while(!pq.empty() && pq.top().second < j){
                pq.pop();
            }
            if((long long)(pq.top().first + k*sum) <= budget) return 1;
            i++;
        }
        if((long long)(pq.top().first + k*sum) <= budget) return 1;
        return 0;
    }

    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int i = 1, j = ct.size();
        int ans = 0;
        while(i <= j){
            int mid = (i+j)/2;
            bool sum = f(mid,ct,rc,budget);
            if(sum == true){
                ans = mid;
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }
};