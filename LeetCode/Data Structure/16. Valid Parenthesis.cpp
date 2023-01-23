/*
Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    map<char,char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';
    for(int index = 0; index < s.size(); index++) {
        if(s[index] == '(' || s[index] == '[' || s[index] == '{')
            st.push(s[index]);
        else if((s[index] == ')' || s[index] == ']' || s[index] == '}')) {
            if(st.empty() || st.top() != m[s[index]])
                return false;
            st.pop();
        }
        
    }
    if(st.empty())
        return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << ((isValid(s) == 1) ? "true":"false") << endl;
}