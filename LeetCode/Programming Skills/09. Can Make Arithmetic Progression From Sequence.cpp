/*
Can Make Arithmetic Progression From Sequence

A sequence of numbers is called an arithmetic progression if the difference 
between any two consecutive elements is the same. Given an array of numbers arr, 
return true if the array can be rearranged to form an arithmetic progression. 
Otherwise, return false.

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

Constraints:

    2 <= arr.length <= 1000
    -106 <= arr[i] <= 106
*/
#include <bits/stdc++.h>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
    if(arr.size() <= 2)
        return true;
    sort(arr.begin(),arr.end());
    int diff = arr[1]-arr[0];
    for(int index = 1; index < arr.size()-1; index++)
        if(arr[index+1]-arr[index] != diff)
            return false;
    return true;    
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int index = 0; index < n; index++)
        cin >> arr[index];
    cout << ((canMakeArithmeticProgression(arr) == 1) ? "true":"false") << endl;
}