class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int cntr = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                    mp[nums[i] * nums[j]]++;
            }
        }
        for (auto [_, i] : mp) {
            cout << i << endl;
                int pro = ((i - 1) * i) / 2;
                cntr += pro * 8;
            }
        
        return cntr;
    }
};