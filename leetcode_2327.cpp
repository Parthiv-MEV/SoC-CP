class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> map(forget, 0);
        int MOD = 1e9 + 7;
        map[0] = 1;
        for (int i = 1; i < n; i++) {
            int newPeople = 0;
            for (int j = delay - 1; j < forget - 1; j++) {
                if (j >= 0) {
                    newPeople = (newPeople + map[j]) % MOD;
                }
            }
            map.pop_back();
            map.insert(map.begin(), newPeople);
        }
        return accumulate(map.begin(), map.end(), 0LL) % MOD;
    }
};
