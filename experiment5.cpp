#include <iostream>
#include <string>

using namespace std;
int main() {   
    string prod[3] = {"s+s", "s*s", "a"};     
    string left[10];  
    string right[10];  
    int l = 0, r = 0;     
    for (int i = 0; i < 3; i++) {       
        if (prod[i][0] == 's') {            
            left[l++] = prod[i].substr(1); 
        } else {
                        right[r++] = prod[i];
        }
    }
    cout << "After removing left recursion:" << endl;    
    cout << "s -> ";
    for (int i = 0; i < r; i++) {
        cout << right[i] << "s'";
        if (i != r - 1) cout << "|"; 
    }
    cout << endl;    
    cout << "s' -> ";
    for (int i = 0; i < l; i++) {
        cout << left[i] << "s'|";
    }
    cout << "epsilon" << endl;
    return 0;
}