/*
Edit Distance

Given two strings word1 and word2, return the minimum number of 
operations required to convert word1 to word2.
You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
int minDistance(string s1, string s2, map<string,map<string,int>>& m) {
    if(s1 == s2)
        return 0;
    if(s1.size() == 0 && s2.size() > 0)
        return s2.size();
    if(s1.size() > 0 && s2.size() == 0)
        return s1.size();
    if(m.count(s1) == 1 && m[s1].count(s2) == 1)
        return m[s1][s2];
    if(s1[0] == s2[0]) 
        m[s1][s2] = minDistance(s1.substr(1),s2.substr(1),m);
    else {
        int ch1 = minDistance(s1.substr(1),s2.substr(1),m);
        int ch2 = minDistance(s1,s2.substr(1),m);
        int ch3 = minDistance(s1.substr(1),s2,m);
        m[s1][s2] = 1+ min(ch1,min(ch2,ch3));
    }
    return m[s1][s2];
}
*/
/*
int minDistance(string s1, string s2, vector<vector<int>>& v) {
    if(s1 == s2)
        return 0;
    if(s1.size() == 0 && s2.size())
        return s2.size();
    if(s1.size() && s2.size() == 0)
        return s1.size();
    if(v[s1.size()][s2.size()] != INT_MAX)
        return v[s1.size()][s2.size()];
    if(s1[0] == s2[0])
        v[s1.size()][s2.size()] = minDistance(s1.substr(1),s2.substr(1),v);
    else {
        int ch1 = minDistance(s1.substr(1),s2.substr(1),v);
        int ch2 = minDistance(s1,s2.substr(1),v);
        int ch3 = minDistance(s1.substr(1),s2,v);
        v[s1.size()][s2.size()] = 1+min(ch1,min(ch2,ch3));
    }
    return v[s1.size()][s2.size()];
}
*/
int minDistance(string s1, string s2) {
    /*
    map<string,map<string,int>> m;
    return minDistance(s1,s2,m);
    */
    /*
    vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1,INT_MAX));
    return minDistance(s1,s2,v);
    */
    /*
    vector<vector<int>> mat(s1.size()+1, vector<int>(s2.size()+1,0));
    for(int row = 0; row <= s1.size(); row++)
        mat[row][0] = row;
    for(int col = 0; col <= s2.size(); col++)
        mat[0][col] = col;
    for(int row = 1; row <= s1.size(); row++) {
        for(int col = 1; col <= s2.size(); col++) {
            if(s1[row-1] == s2[col-1])
                mat[row][col] = mat[row-1][col-1];
            else
                mat[row][col] = 1+min(mat[row-1][col-1],min(mat[row][col-1],mat[row-1][col]));
        }
    }
    return mat[s1.size()][s2.size()];
    */
    int mat[501][501] = {0};
    for(int row = 0; row <= s1.size(); row++)
        mat[row][0] = row;
    for(int col = 0; col <= s2.size(); col++)
        mat[0][col] = col;
    for(int row = 1; row <= s1.size(); row++) {
        for(int col = 1; col <= s2.size(); col++) {
            if(s1[row-1] == s2[col-1])
                mat[row][col] = mat[row-1][col-1];
            else
                mat[row][col] = 1+min(mat[row-1][col-1],min(mat[row][col-1],mat[row-1][col]));
        }
    }
    return mat[s1.size()][s2.size()];
}
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    cout << minDistance(s1,s2) << endl;
}