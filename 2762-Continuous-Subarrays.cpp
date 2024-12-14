class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cntr = 0;
        int i = 0, j = 0;
        // make sure that max and min elment diff dosn't exceed 2
        multiset<int> s;
        while (j < n) {
            
            s.insert(nums[j]);
            
            while (*s.rbegin() - *s.begin() > 2 && i < j) {
                cout << *s.begin() << endl;
                s.erase(s.find(nums[i]));
                i++;
            }

            cntr += j - i + 1;
            j++;
        }
        return cntr;
    }
};