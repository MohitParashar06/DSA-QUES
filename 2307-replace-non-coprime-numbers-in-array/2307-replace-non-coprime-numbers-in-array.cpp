class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b, long long g) {
    return (a / g) * b;  // divide first to prevent overflow
}

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        if(nums.size() == 1) return nums;
        int g = gcd(nums[0],nums[1]);
        if(g == 1){
            st.push(nums[0]);
            st.push(nums[1]);
        }else{
            // cout << lcm(nums[0],nums[1],g) << endl;
            st.push(lcm(nums[0],nums[1],g));
        }
        for(int i = 2; i < nums.size(); i++){
            int n1 = st.top();
            // cout << n1 << " "<< i << endl;;
            st.pop();
            int n2 = nums[i];
            int gc = gcd(n1,n2);
            if(gc == 1){
                st.push(n1);
                st.push(n2);
            }else{
                int l = lcm(n1,n2,gc);
                st.push(l);
                do{
                    int e1 = st.top();
                    st.pop();
                    if(st.empty()) {
                        st.push(e1);break;
                    }
                    int e2 = st.top();
                    st.pop();
                    int g1 = gcd(e1,e2);
                    if(g1 == 1){
                        st.push(e2);
                        st.push(e1);
                        break;
                    }else{
                        st.push(lcm(e1,e2,g1));
                    }
                }while(st.size() > 1);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            // cout << st.top() << " ";
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};