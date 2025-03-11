class Solution {
public:
  bool isVowel(char s) {
        return s == 'a' or s == 'b' or s == 'c';
    }
    long long atleastK(string word, int k) {
        long long cntr = 0;
        int n = word.size();
        map<char, int> vow;

        int i = 0, j = 0, vnum = 0, cnum = 0;
        while (j < n) {
            if (isVowel(word[j])) {
                vnum += (vow[word[j]] == 0);
                vow[word[j]]++;
            }

            cout << vnum << endl;
            while (vnum == 3) {
                cntr+= n - j;
                if (isVowel(word[i])) {
                    if (vow[word[i]] == 1)
                        vnum--;
                    vow[word[i]]--;
                }
                i++;
            }
            j++;
        }
        return cntr;
    }
    int numberOfSubstrings(string s) {
        return atleastK(s , 1);
    }
};