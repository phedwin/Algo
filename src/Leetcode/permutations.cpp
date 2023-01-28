

/*
Given an array nums of distinct integers,
return all the possible permutations.
You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/



#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &curr, vector<bool> &used) {
    if (curr.size() == nums.size()) {
        result.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        curr.push_back(nums[i]);
        backtrack(nums, result, curr, used);
        curr.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    backtrack(nums, result, curr, used);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);
    for (auto &p : permutations) {
        for (auto &n : p) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
