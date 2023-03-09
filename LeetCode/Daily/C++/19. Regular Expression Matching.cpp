/*
Regular Expression Matching

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:

    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/
#include <bits/stdc++.h>
using namespace std;
bool isMatch2(string s, string p, int i, int j, int cache[][21]) {
    if(cache[i][j] != -1)
        return cache[i][j];
    if(i == s.size() && j == p.size())
        return true;
    if(j == p.size())
        return false;
    bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
    if(j+1 < p.size() && p[j+1] == '*')
        cache[i][j] = isMatch2(s,p,i,j+2,cache) || (match && isMatch2(s,p,i+1,j,cache));
    else if(match)
        cache[i][j] = isMatch2(s,p,i+1,j+1,cache);
    else 
        cache[i][j] = false;
    return cache[i][j];
}
bool isMatch(string s, string p) {
    int cache[22][21];
    memset(cache,-1,21*21*sizeof(int));
    return isMatch2(s,p,0,0,cache);
}
int main() {
    string s,p;
    cin >> s >> p;
    cout << ((isMatch(s,p)) ? "true": "false") << endl;
}