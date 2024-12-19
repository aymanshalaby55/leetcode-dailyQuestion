class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            sorted.push_back(i);
        }
        for(int i = 1;i < n;i++){
            sorted[i] += sorted[i - 1];
            arr[i] += arr[i - 1];
        }
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += (arr[i] == sorted[i]);
        }
        return sum;
    }
};