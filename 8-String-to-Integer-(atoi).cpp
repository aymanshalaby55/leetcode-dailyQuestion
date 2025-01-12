class Solution {
public:
    int myAtoi(string s) {
        bool post = 1;
        long ans = 0 , go = 0 , ma = 0;
        cout << INT_MIN;
      for (auto i : s) {
            if (isdigit(i)) {
                ans *= 10;
                ans += i - '0';
                if(ans > INT_MAX || ans < INT_MIN){
                    ma = 1;
                    break;
                }
                go =1;
            } else if (i == '-' && !go) {
                post = 0;
                go = 1;
            }
            else if(i == '+' && !go){
                post = 1;
                go = 1;
            }
            else if(i != ' ' || go){
                break;
            }
        }
        if(!post && ma) ans = INT_MIN;
        else if(ma) ans = INT_MAX;
        else if(!post && ans != 0)ans *= -1;
        return ans;
    }
};