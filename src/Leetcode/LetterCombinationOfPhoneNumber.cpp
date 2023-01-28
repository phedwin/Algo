/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    unordered_map<char, string> mapping{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    res.push_back("");
    for (char c : digits) {
        int n = res.size();
        for (int i = 0; i < n; i++) {
            string t = res.front();
            res.erase(res.begin());
            for (char ch : mapping[c]) {
                res.push_back(t + ch);
            }
        }
    }
    return res;
}
