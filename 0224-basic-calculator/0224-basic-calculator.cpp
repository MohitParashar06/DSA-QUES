class Solution {
public:
    int solve(int& ind, string& s) {
        stack<int> st;
        bool pf = 0, nf = 0;
        int i = ind;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            string num = "";
            if (s[i] == '(') {
                int k = i + 1;
                int val = solve(k, s);
                st.push(val);
                // cout << k << " " << val << endl;
                i = k;
            } else if (s[i] == '+') {
                pf = 1;
                i++;
                continue;
            } else if (s[i] == '-') {
                nf = 1;
                i++;
                continue;
            } else if (s[i] == ')') {
                ind = i;
                // cout << ind << "-> " << st.top()<<endl;
                return st.top();
            } else if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
                while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num += s[i + 1];
                    i++;
                }
                int n = stoi(num);
                st.push(n);
                // cout << st.top() << " " << pf << " " << nf  << " " << ind <<
                // endl;
            }
            if (!st.empty()) {
                if (pf == 1) {

                    int top = st.top();
                    st.pop();
                    int top2 = 0;
                    if (!st.empty()) {
                        top2 = st.top();
                        st.pop();
                    }
                    // cout << i << " " << top << " " << top2 << endl;
                    st.push(top + top2);
                    pf = 0;
                }
                if (nf == 1) {
                    int top = st.top();
                    st.pop();
                    int top2 = 0;
                    if (!st.empty()) {
                        top2 = st.top();
                        st.pop();
                    }
                    // cout << i << " " << top << " , " << top2 << endl;
                    st.push(top2 - top);
                    nf = 0;
                }
            }
            i++;
        }
        return 0;
    }

    int calculate(string s) {
        stack<int> st;
        bool pf = 0, nf = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            string num = "";
            if (s[i] == '(') {
                int k = i + 1;
                int val = solve(k, s);
                st.push(val);
                // cout << k << " " << val << endl;
                i = k;
            } else if (s[i] == '+') {
                pf = 1;
                i++;
                continue;
            } else if (s[i] == '-') {
                nf = 1;
                i++;
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
                while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num += s[i + 1];
                    i++;
                }
                int n = stoi(num);
                st.push(n);
                // cout << st.top() << " " << pf << " " << nf << endl;
            }
            if (!st.empty()) {
                if (pf == 1) {

                    int top = st.top();
                    st.pop();
                    int top2 = 0;
                    if (!st.empty()) {
                        top2 = st.top();
                        st.pop();
                    }
                    st.push(top + top2);
                    pf = 0;
                }
                if (nf == 1) {
                    int top = st.top();
                    st.pop();
                    int top2 = 0;
                    if (!st.empty()) {
                        top2 = st.top();
                        st.pop();
                    }
                    st.push(top2 - top);
                    nf = 0;
                }
            }
            i++;
        }
        return st.top();
    }
};