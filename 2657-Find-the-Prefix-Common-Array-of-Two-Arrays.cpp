class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        int cntr = 0;
        map<int , int> mp;
        for(int i = 0;i < n; i++){
            mp[A[i]]++ , mp[B[i]]++;
            cntr += (mp[A[i]] == 2);
            cntr += (mp[B[i]] == 2  && A[i] != B[i]);
            ans.push_back(cntr);
        }
        return ans;
    }
};