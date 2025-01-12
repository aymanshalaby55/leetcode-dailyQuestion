class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st, lock;
        int n = s.size(), sum = 0;
        if (n % 2 == 1) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            bool canChange = locked[i] - '0';
            sum += canChange == 0;
            if (!canChange) {
                lock.push(i);
            } else {
                if (s[i] == ')') {
                    if (!st.empty()) {
                        st.pop();
                    } else if (!lock.empty()) {
                        lock.pop();
                    } else {
                        return false;
                    }
                } else {
                        st.push(i);
                }
            }
        }
        while (!st.empty() && !lock.empty() &&
               st.top() < lock.top()) {
            st.pop();
            lock.pop();
        }
        int sz = st.size(), sz2 = lock.size();
        cout << sz << endl << " aaa";
        return st.empty();
    }
};