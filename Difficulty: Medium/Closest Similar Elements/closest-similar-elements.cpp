
class Solution {
  public:
    bool closestSimilarElements(int n, vector<int> &arr, int indexDifference,
                                int valueDifference) {
        // code here
        vector<vector<int>> pr;
        for(int i = 0; i < n; i++){
            pr.push_back({arr[i],i});
        }
        
        for(int i = 0; i < n-1; i++){
            if(abs(i-(i+1)) <= indexDifference &&
            abs(arr[i] - arr[i+1]) <= valueDifference){
                return true;
            }
        }
        
        sort(pr.begin(), pr.end());
        for(int i = 0; i < n-1; i++){
            // cout << pr[i][0] << ", " << pr[i][1] << " -> ";
            if(abs(pr[i][1]-pr[i+1][1]) <= indexDifference &&
            abs(pr[i][0] - pr[i+1][0]) <= valueDifference){
                return true;
            }
        }
        return false;
    }
};
