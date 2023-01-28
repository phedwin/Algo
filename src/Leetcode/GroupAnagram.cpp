
/*
Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters
of a different word or phrase, typically using all the original letters
exactly once.

*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        map[key].push_back(str);
    }
    vector<vector<string>> res;
    for (auto m : map) {
        res.push_back(m.second);
    }
    return res;
}
