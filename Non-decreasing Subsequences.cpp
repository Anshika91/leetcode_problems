#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;
    findSubsequencesHelper(nums, 0, curr, res);
    return res;
}

void findSubsequencesHelper(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res) {
    if (curr.size() >= 2) {
        res.push_back(curr);
    }
    unordered_set<int> used;
    for (int i = start; i < nums.size(); i++) {
        if (used.count(nums[i])) continue;
        used.insert(nums[i]);
        if (curr.empty() || nums[i] >= curr.back()) {
            curr.push_back(nums[i]);
            findSubsequencesHelper(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> res = findSubsequences(nums);
    for (auto v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
