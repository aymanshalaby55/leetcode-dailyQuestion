class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cntr = 0;
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1;i < n;i++){
            pref[i] = pref[i - 1] + nums[i];
        }

        for(int i = 1;i < n;i++){
            cntr += (pref[i - 1] >= (pref[n - 1] - pref[i - 1]));
        }
        return cntr;
    }
};