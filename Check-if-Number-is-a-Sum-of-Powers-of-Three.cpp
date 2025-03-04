class Solution {
public:
    bool checkPowersOfThree(int n) {

        // 3
        while (n) {
            if(n % 3 == 2){
                return false;
            }
            n /= 3;
        }
        return true;
    }
};