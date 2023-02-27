/*
Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by 
adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional 
letters onto the end of the merged string.
Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

Constraints:

    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
string mergeAlternately(string word1, string word2) {
    int index1 = 0, index2 = 0, count = 1;
    string word = "";
    while(index1 < word1.size() && index2 < word2.size()) {
        if(count&1)
            word += word1[index1++];
        else
            word += word2[index2++];
        count++;
    }
    while(index1 < word1.size())
        word += word1[index1++];
    while(index2 < word2.size())
        word += word2[index2++];
    return word;
}
int main() {
    string word1,word2;
    cin >> word1 >> word2;
    cout << mergeAlternately(word1,word2) << endl;
}