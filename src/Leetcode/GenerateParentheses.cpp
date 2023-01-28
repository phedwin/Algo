/*


Given n pairs of parentheses,
write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            res.push_back(curr);
            return;
        }
        if (open < max)
            backtrack(res, curr + "(", open + 1, close, max);
        if (close < open)
            backtrack(res, curr + ")", open, close + 1, max);
    }
};
