class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // just hash the number with it's index.
        map<int, int> mp;
        long long n = nums.size();
        for (int i = 0; i < n; i++) {
            // save what
            mp[nums[i] - i]++;
        }

        long long cntr = 0;
        map<int , int> frq;
        // find good pairs first...
        for (int j = 1; j < n; j++) {
            frq[nums[j] - j]++;
            cntr += (mp[nums[j] - j] - frq[nums[j] - j]);
            cout << cntr << " " << nums[j] - j << endl;
        }
        cout << cntr << endl;
        // find number of pairs now...
        long long sum = (n * (n - 1)) / 2;
        return  sum - cntr;
    }
};