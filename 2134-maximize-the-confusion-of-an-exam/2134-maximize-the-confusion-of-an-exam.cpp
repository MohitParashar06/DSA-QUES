class Solution {
public:

    int f(string ak, int k, char ch){
        int maxi = 0, i = 0; queue<int> q;
        for(int j = 0; j < ak.size(); j++){
            if(ak[j] == ch){
                maxi = max(maxi,j-i+1);
            }else{
                if(k > 0){
                    k--;
                    maxi = max(maxi,j-i+1);
                }else{
                    int d = q.front();
                    q.pop();
                    while(i <= d){
                        i++;
                    }
                    maxi = max(maxi,j-i+1);
                }
                q.push(j);
            }
            // cout << j << " " << i << " " << maxi << " " << ch << endl;
        }
        // cout << maxi << endl;
        return maxi;
    }    

    int maxConsecutiveAnswers(string ak, int k) {
        // int j = ak.size();
        // int i = 1;
        // int ans = 0;
        // while(i <= j){
        //     int mid = (i+j)/2;
        //     if(f(mid,ak,k)){
        //         ans = mid;
        //         i = mid+1;
        //     }else{
        //         j = mid-1;
        //     }
        // }
        // return ans;
        return max(f(ak,k,'T'), f(ak,k,'F'));
    }
};