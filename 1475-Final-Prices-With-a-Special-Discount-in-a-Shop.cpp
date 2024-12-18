class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        stack<int> st;
        vector<int> discount(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                discount[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << discount[i] << " "; 
            nums[i] -= discount[i];
        }
        return nums;
    }
};