#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Fixed array initialization and missing semicolon
    string prod[3] = {"s+s", "s*s", "a"}; 
    
    string left[10];  // Stores alpha (recursive part)
    string right[10]; // Stores beta (non-recursive part)
    
    // 2. Fixed variable initialization ('o' to '0') and added 'l' counter
    int l = 0, r = 0; 

    // 3. Fixed loop syntax and logic
    for (int i = 0; i < 3; i++) {
        // Check if the production starts with the non-terminal 's'
        if (prod[i][0] == 's') {
            // It is left recursive: Store everything AFTER the first 's'
            // changed substr(l) to substr(1) to skip the first character
            left[l++] = prod[i].substr(1); 
        } else {
            // It is not left recursive
            right[r++] = prod[i];
        }
    }

    cout << "After removing left recursion:" << endl;

    // 4. Output Logic for S -> beta S
    cout << "s -> ";
    for (int i = 0; i < r; i++) {
        cout << right[i] << "s'";
        if (i != r - 1) cout << "|"; // Fixed "1" to "|"
    }
    cout << endl;

    // 5. Output Logic for S' -> alpha S' | epsilon
    cout << "s' -> ";
    for (int i = 0; i < l; i++) {
        cout << left[i] << "s'|";
    }
    cout << "epsilon" << endl; // Fixed spelling of epsilon

    return 0;
}