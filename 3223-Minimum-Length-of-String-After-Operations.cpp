class Solution {
public:
    int minimumLength(string s) {
       map<int , int> mp;
       for(auto i : s){
        mp[i]++;
       }
       int sum = 0;
       for(auto i : mp){
        int n = i.second;
        if(n & 1){
            sum += 1;
        }
        else sum += 2;
       }
       return sum;
    }
};