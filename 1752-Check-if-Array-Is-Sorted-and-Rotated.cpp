class Solution {
public:
    bool check(vector<int>& nums) {
        int cntr = (nums[0] < nums[nums.size() - 1]);
        for(int i = 1;i < size(nums);i++){
            cntr += (nums[i] < nums[i - 1]);
        }
        return cntr <= 1;
    }
};