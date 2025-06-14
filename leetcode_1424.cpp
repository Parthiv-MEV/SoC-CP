class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> diagonals;
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                if (diagonals.size() <= i + j)
                    diagonals.resize(i + j + 1);
                diagonals[i + j].push_back(nums[i][j]);
                ++total;
            }
        }
        vector<int> ans;
        ans.reserve(total);
        for (auto& d : diagonals) {
            for (auto it = d.rbegin(); it != d.rend(); ++it)
                ans.push_back(*it);
        }
        return ans;
    }
};