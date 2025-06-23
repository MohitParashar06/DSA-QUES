class Solution {
public:

    bool pali(string s){
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j]) return 0;
            i++;j--;
        }
        return 1;
    }
    string base(long long i, int k) {
    if (i == 0) return "0";

    string result;
    bool isNegative = false;

    if (i < 0) {
        isNegative = true;
        i = -i;
    }

    while (i > 0) {
        int rem = i % k;
        result = char((rem < 10) ? ('0' + rem) : ('A' + rem - 10)) + result;
        i /= k;
    }

    if (isNegative) result = "-" + result;
    return result;
}
    long long kMirror(int k, int n) {
        long long l = 1;
        long long sum = 0;
        while(n > 0){
            int hl = (l+1)/2;
            long long min_val = pow(10,hl-1);
            long long max_val = pow(10,hl)-1;
            for(int i = min_val; i <= max_val; i++){
                string fr = to_string(i);
                string sec = fr;
                reverse(sec.begin(), sec.end());
                string pal = "";
                if(l%2 == 0){
                    pal = fr + sec;
                }
                else{
                    pal = fr + sec.substr(1);
                }
                long long num = stoll(pal);
                string bas = base(num,k);
                if(pali(bas)){
                    sum += num;
                    n--;
                    if(n == 0) break;
                }
            }
            l++;
        }
        return sum;
    }
};