class Solution {
public:
    struct player {
        int value;
        int index;
        bool operator<(const player& other) const {
            if (value != other.value) {
                return value >
                       other.value; 
            }
            return index > other.index; // Larger indices have lower priority
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<player> p;
        for (int i = 0; i < nums.size(); i++) {
            p.push({nums[i], i});
        }
        while (k--) {
            nums[p.top().index] = p.top().value * multiplier;
            int addedValue = nums[p.top().index];
            int index = p.top().index;
            p.pop();
            p.push({addedValue, index});
        }
        // while (!p.empty()) {
        //     nums[p.top().index] = p.top().value;
        //     p.pop();
        // }
        return nums;
    }
};