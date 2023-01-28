/*
Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and 
change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing 
the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:

    1 <= s.length <= 105
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    /*
        Solution 1:- Time Complexity:- O(s.length())
                     Space Complexity:- O(s.length())

    */
    int left = 0, right = 0, maxfreq = 0, maxlength = 0;   
    map<char,int> m;
    while(right < s.size()) {
        m[s[right]]++;
        for(auto itr = m.begin(); itr != m.end(); itr++)
            maxfreq = max(maxfreq,itr->second);
        while((right-left+1)-maxfreq > k) {
            m[s[left]]--;
            left++;
        }
        maxlength = max(maxlength,right-left+1);
        right++;
    }
    return maxlength;
}

int main() {
    string s; int k;
    cin >> s >> k;
    cout << characterReplacement(s,k) << endl;
}