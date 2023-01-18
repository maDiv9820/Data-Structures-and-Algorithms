/*
Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:

    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    /*
        Time Complexity:- O(n)
        Space Complexity:- O(n)
        where n is the size of the s
    */
    int palindromeSize = 0;
    map<char,int> m;
    for(int index = 0; index < s.size(); index++) {
        m[s[index]]++;
        if(m[s[index]] % 2 == 0) {
            palindromeSize += m[s[index]];
            m[s[index]] = 0;
        }
    }
    for(auto x: m)
        if(x.second == 1) {
            palindromeSize++;
            break;
        }
    return palindromeSize;
}

int main() {
    string s;
    cin >> s;
    int palindromeSize = longestPalindrome(s);
    cout << palindromeSize << endl;
}