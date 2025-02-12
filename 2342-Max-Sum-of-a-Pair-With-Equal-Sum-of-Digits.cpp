class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int , vector<int>> mp;
        int ans = -1;
        for(int i = 0;i < nums.size();i++){
            int tmp = nums[i];
            int sum = 0;
            while(tmp) {
                sum += tmp %10;
                tmp /= 10;
            }
            mp[sum].push_back(nums[i]);
        } 
        for(auto i : mp){
            if(i.second.size() >= 2){
                sort(i.second.begin() , i.second.end() , greater<int>());
                ans = max(ans ,i.second[1] + i.second[0]);
            }
        }
        return ans;
    }
};