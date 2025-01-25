class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        auto arr = nums;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<queue<int>> groups(n);
        map<int, int> mp;
        mp[arr[0]] = 0;
        groups[0].push(arr[0]);
        int level = 0;
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) <= limit) {
                groups[level].push(arr[i]);
                mp[arr[i]] = level;
            } else {
                level++;
                groups[level].push(arr[i]);
                mp[arr[i]] = level;
            }
        }
        vector<int> ans;
        for (auto i : nums) {
            int le = mp[i];
            ans.push_back(groups[le].front());
            groups[le].pop();
        }
        return ans;
    }
};