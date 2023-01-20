/*
Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Constraints:

    1 <= s.length, t.length <= 5 * 104    s and t consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;
    unordered_map<char,int> m;
    for(char ch: s)
        m[ch]++;
    for(char ch: t) {
        if(m.count(ch) == 0 || m[ch] == 0)
            return false;
        m[ch]--;
    }
    return true;
}

int main() {
    string s,t;
    cin >> s >> t;
    cout << ((isAnagram(s,t) == 1) ? "true":"false") << endl;
}