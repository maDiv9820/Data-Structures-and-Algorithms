#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    // Solution Time Complexity:- O(n), Space Complexity:- O(n)
    map<char,char> m1,m2;
    for(int index = 0; index < s.size(); index++) {
        if(m1.count(s[index]) == 0 && m2.count(t[index]) == 0) {
            m1[s[index]] = t[index];
            m2[t[index]] = s[index];
        }
        else if(m1.count(s[index]) == 0 || m2.count(t[index]) == 0 
                || m1[s[index]] != t[index] || m2[t[index]] != s[index])
            return false;
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    bool ans = isIsomorphic(s,t);
    cout << ((ans == 0)? "false":"true") << endl;
}