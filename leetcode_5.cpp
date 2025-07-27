#include <string>
using namespace std;
class Solution {
    pair<int, int> extend(const string& s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) { i--; j++; }
        return {i+1, j};
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            auto [l1, r1] = extend(s, i-1, i+1);
            auto [l2, r2] = extend(s, i-1, i);
            if (r1-l1 > res.size()) res = s.substr(l1, r1-l1);
            if (r2-l2 > res.size()) res = s.substr(l2, r2-l2);
        }
        return res;
    }
};
