/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.
*/

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<char>& s) {
    /*
        Solution 1: Using inbuild function
        Time Complexity: O(n)
        Space Complexity: O(1)
        where n is the length of the s
    */
    reverse(s.begin(),s.end());
}

int main() {
    vector<char> s;
    char ch;
    cin >> ch;
    while(ch != '\n') {
        s.push_back(ch);
        cin >> ch;
    }
    reverse(s);
    for(char ch: s)
        cout << ch;
    cout << endl;
}