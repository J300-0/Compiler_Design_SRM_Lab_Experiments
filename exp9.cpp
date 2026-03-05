#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Production {
    string lhs;
    string rhs;
};

int main() {
    int num_productions;
    cout << "Enter number of productions: ";
    cin >> num_productions;

    vector<Production> rules(num_productions);
    cout << "Enter productions (e.g., S->aSb):" << endl;
    for (int i = 0; i < num_productions; ++i) {
        string prod;
        cin >> prod;
        int arrow_pos = prod.find("->");
        rules[i].lhs = prod.substr(0, arrow_pos);
        rules[i].rhs = prod.substr(arrow_pos + 2);
    }

    string input;
    cout << "Enter input string: ";
    cin >> input;

    input += "$";  
    string stack = "$"; 
    string action = "";

    cout << "\nLeft align formats:" << left << endl;
    cout << setw(20) << "Stack" << setw(20) << "Input" << "Action" << endl;
    cout << "------------------------------------------------" << endl;

    int i = 0;
    while (true) {
        cout << setw(20) << stack << setw(20) << input.substr(i) << action << endl;
        
        if (stack == "$" + rules[0].lhs && input[i] == '$') {
            cout << setw(20) << stack << setw(20) << "$" << "Accept" << endl;
            break;
        }

        bool reduced = false;
        for (const auto& rule : rules) {
            if (stack.length() >= rule.rhs.length()) {
                string top_of_stack = stack.substr(stack.length() - rule.rhs.length());
                if (top_of_stack == rule.rhs) {
                    stack.erase(stack.length() - rule.rhs.length());
                    stack += rule.lhs;
                    action = "Reduce " + rule.lhs + "->" + rule.rhs;
                    reduced = true;
                    break;
                }
            }
        }

        if (reduced) continue;

        // Shift next input symbol onto the stack
        if (input[i] != '$') {
            stack += input[i];
            action = "Shift " + string(1, input[i]);
            i++;
        } else {
            cout << setw(20) << stack << setw(20) << "$" << "Reject (Parsing Error)" << endl;
            break;
        }
    }

    return 0;
}