/*
Permutation in String

Given two strings s1 and s2, return true if s2 contains 
a permutation of s1, or false otherwise. In other words, return true 
if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
bool isSame(int a[], int b[]) {
    for(int index = 0; index < 26; index++)
        if(a[index] != b[index])
            return false;
    return true;
}
bool checkInclusion(string s1, string s2) {
    int pos1 = 0, pos2 = 0;
    int a[26] = {0}, b[26] = {0};
    for(int index = 0; index < s1.size(); index++)
        a[s1[index]-'a']++;
    while(pos2 < s2.size()) {
        b[s2[pos2]-'a']++;
        if(pos2-pos1+1 == s1.size() && isSame(a,b))            
            return true;
        else if(pos2-pos1+1 < s1.size())
            pos2++;
        else {
            b[s2[pos1]-'a']--;
            pos1++;
            pos2++;
        }
    }
    return false;
}
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    cout << ((checkInclusion(s1,s2) == 1) ? "true":"false") << endl;
}