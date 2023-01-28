/*

Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    if (nums.empty()) return result;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[left] != target) return result;
    result[0] = left;
    right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2 + 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    result[1] = right;
    return result;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "Starting position: " << result[0] << endl;
    cout << "Ending position: " << result[1] << endl;
    return 0;
}
