class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score{};
        vector<pair<int, int>> pos(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pos[i].first = nums[i], pos[i].second = i;
        }
        sort(pos.begin(), pos.end());
        for (int i = 0; i < nums.size(); i++) {
            int index = pos[i].second;
            score += nums[index];
            if (nums[index] == 0)
                continue;
            nums[index] = 0;
            cout << index << " ";
            if (index + 1 < nums.size()) {
                nums[index + 1] = 0;
            }
            if (index - 1 >= 0) {
                nums[index - 1] = 0;
            }
        }
        return score;
    }
};