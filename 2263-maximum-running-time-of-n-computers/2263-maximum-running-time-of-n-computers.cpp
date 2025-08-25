class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        // return 0;
        sort(bat.begin(), bat.end());
        long long s = 0;
        // for(auto it : bat) s+=it;
        // if(n == 2) return s/2;
        long long ans = 0;
        int i = bat.size()-n;
        vector<long long int> temp;
        for(i; i < bat.size(); i++){
            temp.push_back(bat[i]);
        }
        // for(auto it : temp) cout << it << " ";
        long long sum = 0;
        // cout << endl << i << endl;
        for(int j = 0; j < bat.size()-n; j++){
            sum += bat[j];
        }
        long long int cnt = 1;
        i=0;
        // cout << temp.size() <<"    ";
        ans = temp[i];
        while(sum > 0){
            long long x = cnt;
            if(i+1 >= temp.size()) break;
            x = x * (temp[i+1]-temp[i]);
            if(sum >= x){
                sum -= x;
                ans=temp[i+1];

                i++;cnt++;
            }else{
                long long mod = sum/(i+1);
                ans = max(ans, temp[i]+mod);
                sum = 0;
            }
            // cout << sum << " " << i  << " " << (temp[i+1]-temp[i]) << " " << cnt<< endl;
        }
        if(i+1 >= temp.size()){
            cout << sum << endl;
            long long s = sum/temp.size();
            return temp[temp.size()-1]+s;
        }
        return ans + sum/temp.size();
    }
};