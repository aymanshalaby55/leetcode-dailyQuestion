class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = nums[0];
        int n = nums.size();
        for(int i = 0;i < n;i++){
            sum = max(sum , 0);
            sum += nums[i];
            max_sum = max(sum , max_sum);
        }
        return max_sum;
    }
};