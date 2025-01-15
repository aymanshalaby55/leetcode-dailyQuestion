class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size() - 1, n = h.size(), sum = 0;
        while (j > i) {
            int area = (j - i) * (min(h[i], h[j]));
            cout << i;
            if (area >= sum) {
                sum = area;
            }
            (h[i] < h[j]) ? i++ : j--;
        }
        return sum;
    }
};