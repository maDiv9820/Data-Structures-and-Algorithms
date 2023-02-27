/*
Goal Parser Interpretation

You own a Goal Parser that can interpret a string command. 
The command consists of an alphabet of "G", "()" and/or "(al)" in some order. 
The Goal Parser will interpret "G" as the string "G", "()" as the string "o", 
and "(al)" as the string "al". The interpreted strings are then concatenated 
in the original order. Given the string command, return the Goal Parser's 
interpretation of command.

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"

Constraints:

    1 <= command.length <= 100
    command consists of "G", "()", and/or "(al)" in some order.
*/
#include <bits/stdc++.h>
using namespace std;
string interpret(string command) {
    string word = "";
    int index = 0;
    while(index < command.size()) {
        int size = command.size()-index;
        if(size >= 4 && command.substr(index,4) == "(al)")  {
            word += "al";
            index += 4;
        }
        else if(size >= 2 && command.substr(index,2) == "()") {
            word += "o";
            index += 2;
        }
        else {
            word += command[index];
            index += 1;
        }
    }
    return word;
}
int main() {
    string command;
    cin >> command;
    cout << interpret(command) << endl;
}