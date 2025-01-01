class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0 , one = 0;
        
        for(int i = 0;i < n;i++){
            one += s[i] - '0';
        }
        int ma = 0;
        for(int i = 0;i < n - 1;i++){
            if(s[i] == '0'){
                zero++;
            }
            else one--;
            ma = max(ma , zero + one);
        }
        return ma;
        //2 splite ->
        // find some
    }
};