/*
First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

Constraints:

    1 <= s.length <= 105
    s consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> m;
    for(char ch:s)
        m[ch]++;
    for(int index = 0; index < s.size(); index++)
        if(m[s[index]] == 1)
            return index;
    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
}