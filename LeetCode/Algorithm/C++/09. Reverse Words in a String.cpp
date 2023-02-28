/*
Reverse Words in a String III

Given a string s, reverse the order of characters in each word within a 
sentence while still preserving whitespace and initial word order. 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD" 

Constraints:

    1 <= s.length <= 5 * 104
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    /*
        Time Complexity:- O(n)
        Space Complexity:- O(1)
    */
    string reverseString = "", substr;
    int start = 0, end = 0;
    for(int index = 0; index < s.size(); index++) {
        if(s[index] == ' ') {
            substr = s.substr(start,index-start);
            reverse(substr.begin(),substr.end());
            reverseString += (substr + " ");
            start = index+1;
        }
    }
    substr = s.substr(start);
    reverse(substr.begin(),substr.end());
    reverseString += substr;
    return reverseString;
}

int main() {
    string s;
    getline(cin,s,'\n');
    string reversedString = reverseWords(s);
    cout << reversedString << endl;
}