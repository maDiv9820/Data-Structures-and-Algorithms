/*
Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order. An Anagram is a word or phrase formed by rearranging the 
letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:

    1 <= s.length, p.length <= 3 * 104
    s and p consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    /*
        Solution 1:- Find all the substrings with length p.size() and 
                     comparing whether no of chars in substring is same as in p or not

                     Time Complexity:- O(n*m)
                     Space Complexity:- O(m)
                     where n is the size of s and m is the size of p
    
    vector<int> indices;
    map<char,int> ms,mp;
    for(char ch: p)
        mp[ch]++;
    for(int index = 0; index < s.size(); index++) {
        string str = s.substr(index,p.size());
        if(str.size() != p.size())
            continue;
        bool found = true;
        for(char ch: str)
            ms[ch]++;
        for(auto itr = ms.begin(); itr != ms.end(); itr++) {
            if(mp.find(itr->first) == mp.end() || mp[itr->first] != itr->second) {
                found = false;
                break;
            }
        }
        if(found)
            indices.push_back(index);
        ms.clear();
    }
    return indices;
    */
    /*
        Solution 2:- Sliding Window Algorithm
                     Time Complexity:- O(n)
                     Space Complexity:- O(m)
                     where n and m are the size of s and p.
    */
    vector<int> indices;
    if(p.size() > s.size())
        return indices;
    int start = 0, end = p.size()-1;
    map<char,int> sCount, pCount;
    for(char ch: p)
        pCount[ch]++;
    for(int index = start; index <= end; index++)
        sCount[s[index]]++;
    while(end < s.size()) {
        bool found = true;
        for(auto itr = pCount.begin(); itr != pCount.end(); itr++) {
            if(sCount.count(itr->first) == 0 || sCount[itr->first] != itr->second) {
                found = false;
                break;
            }
        }
        if(found)
            indices.push_back(start);
        sCount[s[start]]--;
        start++; end++;
        sCount[s[end]]++;
    }
    return indices;
}

int main() {
    string s,p;
    cin >> s >> p;    
    vector<int> indices = findAnagrams(s,p);
    for(int index: indices)
        cout << index << " ";
    cout << endl;
}