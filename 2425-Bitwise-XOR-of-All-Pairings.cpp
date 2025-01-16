class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        bool nums1Odd = nums1.size() % 2 != 0;
        bool nums2Odd = nums2.size() % 2 != 0;

        if (nums1Odd) {
            for (int num : nums2) {
                ans ^= num;
            }
        }
        if (nums2Odd) {
            for (int num : nums1) {
                ans ^= num;
            }
        }

        return ans;
    }
};