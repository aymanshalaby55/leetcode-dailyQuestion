class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int , pair<int , int>> mp;
        map<int , int> row , col;
        for(int i =0;i < m;i++){
            for(int j = 0; j < n;j++){
                mp[mat[i][j]] = {i , j};
            }
        }
        int ans = 0;
        for(int i = 0;i < n * m;i++){
            int index = arr[i];
            auto [x , y] = mp[index];
            cout << arr[i] << " " << x << " " << y << endl;
            row[x]++;
            col[y]++;
            if(row[x] == n || col[y] == m){
                ans =  i;
                break;
            }
        }
        return ans;
    }
};