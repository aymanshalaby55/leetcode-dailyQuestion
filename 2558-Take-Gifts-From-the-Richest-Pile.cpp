class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long rem = 0;
        priority_queue<int> q;
        for (auto i : gifts)
            q.push(i);
        while (k--) {
            int sq = sqrt(q.top());
            q.pop();
            q.push(sq);
        }
        while (!q.empty()) {
            cout << q.top() << ' ';
            rem += q.top();
            q.pop();
        }
        return rem;
    }
};