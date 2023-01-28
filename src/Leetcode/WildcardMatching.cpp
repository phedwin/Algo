/*
iven an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/


#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    int i = 0, j = 0, asterisk = -1, match;
    while (i < m) {
        if (j < n && p[j] == '*') {
            match = i;
            asterisk = j++;
        }
        else if (j < n && (s[i] == p[j] || p[j] == '?')) {
            i++;
            j++;
        }
        else if (asterisk >= 0) {
            i = ++match;
            j = asterisk + 1;
        }
        else return false;
    }
    while (j < n && p[j] == '*') j++;
    return j == n;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}