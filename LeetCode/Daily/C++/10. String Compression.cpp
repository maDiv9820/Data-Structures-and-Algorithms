/*
String Compression

Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:

    If the group's length is 1, append the character to s.
    Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, 
be stored in the input character array chars. Note that group lengths 
that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/
#include <bits/stdc++.h>
using namespace std;
int compress(vector<char>& chars) {
    string str = "";
    for(const char ch: chars)
        str += ch;
    string str1 = "";
    int index = 0;
    while(index < str.size()) {
        int count = 1, tempindex = index+1;
        while(tempindex < str.size() && str[index] == str[tempindex]) {
            count++;
            tempindex++;
        }
        str1 += str[index];
        if(count > 1)
            str1 += to_string(count);
        index = tempindex;
    }
    for(int index = 0; index < str1.size(); index++)
        chars[index] = str1[index];
    return str1.size();
}
int main() {
    int n;
    cin >> n;
    vector<char> chars(n,0);
    for(int index = 0; index < n; index++)
        cin >> chars[index];
    int size = compress(chars);
    for(int index = 0; index < size; index++)
        cout << chars[index] << " ";
    cout << endl;
}