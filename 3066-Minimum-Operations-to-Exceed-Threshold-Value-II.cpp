class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // what to do make a priority queue or?
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (auto i : nums) {
            q.push(i);
        }
        long long cntr = 0;
        while (q.top() < k) {
            long long i = q.top();
            q.pop();
            long long j = q.top();
            q.pop();
            long long val = min(i, j) * 2 + max(i, j);
            q.push(val);
            cntr++;
        }
        return cntr;
    }
};