class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right;
        int cntr = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                right.push_back(nums[i]);
            }else if(nums[i] == pivot){
                cntr++;
            } 
            else {
                left.push_back(nums[i]);
            }
        }
        while(cntr--){
            left.push_back(pivot);
        }
        // sort(right.begin() , right.end());
        // sort(left.begin() , left.end());

        for (auto i : right) {
            left.push_back(i);
        }
        return left;
    }
};