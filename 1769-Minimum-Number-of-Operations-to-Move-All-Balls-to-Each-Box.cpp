class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans , place;
        int n = boxes.size();
        for(int i = 0;i < n;i++){
            if(boxes[i] == '1'){
                place.push_back(i);
            }
        }

        for(int i = 0;i < n;i++){
            int cntr = 0;
            for(auto j : place){
                cntr += abs(j - i);
            }

            ans.push_back(cntr);
        }
        return ans;
    }
};