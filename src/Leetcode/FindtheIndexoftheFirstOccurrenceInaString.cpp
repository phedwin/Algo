
/*
Given two strings needle and haystack,
return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0; // if needle is empty, return 0
    if (haystack.size() < needle.size()) return -1; // if needle is larger than haystack, return -1
    int n = haystack.size();
    int m = needle.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        for (; j < m; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == m) return i;
    }
    return -1;
}
