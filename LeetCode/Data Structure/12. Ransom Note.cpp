/*
Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by 
using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> m;
    for(char ch:magazine)
        m[ch]++;
    for(char ch:ransomNote) {
        if(m.count(ch) == 0 || m[ch] == 0)
            return false;
        m[ch]--;
    }
    return true;
}

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    cout <<((canConstruct(ransomNote,magazine) == 1) ? "true":"false") << endl;
}