#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    /*Solution, Time Complexity:- O(n), 
                Space Complexity: O(n) 
                where n is max(t.size(), s.size())*/
    if(s.size() == 0)
        return true;
    if(t.size() == 0 && s.size() != 0)
        return false;
    if(s[0] == t[0])
        return isSubsequence(s.substr(1), t.substr(1));
    return isSubsequence(s,t.substr(1));
}

int main() {
    string s,t;
    cin >> s >> t;
    bool ans = isSubsequence(s,t);
    cout << ((ans == 1) ? "true":"false") << endl;
}