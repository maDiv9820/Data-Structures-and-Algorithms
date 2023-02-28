#include <bits/stdc++.h>
using namespace std;

int firstBadVersion(int n) {
    int firstbadversion = INT_MIN;
    for(int start = 1, end = n; start <= end;) {
        int mid = start + (end-start)/2;
        // if(isBadVersion(mid)) {
        //     firstbadversion = mid;
        //     end = mid-1;
        // }
        // else
            start = mid+1;
    }
    return firstbadversion;
}

int main() {
    int n;
    cin >> n;
    int firstbadversion = firstBadVersion(n);
    cout << firstbadversion << endl;
}