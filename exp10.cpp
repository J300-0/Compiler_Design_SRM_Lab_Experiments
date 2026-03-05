#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Item {
    string lhs;
    string rhs;
    int dot_pos;

    bool operator<(const Item& other) const {
        if (lhs != other.lhs) return lhs < other.lhs;
        if (rhs != other.rhs) return rhs < other.rhs;
        return dot_pos < other.dot_pos;
    }
};

void printAugmentedGrammar(const vector<pair<string, string>>& rules) {
    cout << "\n2. Augmented Grammar:" << endl;
    for (const auto& rule : rules) {
        cout << rule.first << " -> " << rule.second << endl;
    }
}

int main() {
    int num_productions;
    cout << "Enter number of productions: ";
    cin >> num_productions;

    vector<pair<string, string>> rules;
    cout << "Enter productions (e.g., S->AA):" << endl;
    
    string start_symbol = "";
    for (int i = 0; i < num_productions; ++i) {
        string prod;
        cin >> prod;
        int arrow_pos = prod.find("->");
        string lhs = prod.substr(0, arrow_pos);
        string rhs = prod.substr(arrow_pos + 2);
        
        if (i == 0) start_symbol = lhs;
        rules.push_back({lhs, rhs});
    }


    vector<pair<string, string>> augmented_rules;
    augmented_rules.push_back({start_symbol + "'", start_symbol});
    for (const auto& rule : rules) {
        augmented_rules.push_back(rule);
    }

    cout << "\n1. Numbering the productions:" << endl;
    for (size_t i = 0; i < rules.size(); ++i) {
        cout << i + 1 << ". " << rules[i].first << " -> " << rules[i].second << endl;
    }

    printAugmentedGrammar(augmented_rules);

    cout << "\n3. LR(0) Items (Initial Closure - I0):" << endl;
    cout << "I0:" << endl;

    vector<Item> I0;
    I0.push_back({augmented_rules[0].first, augmented_rules[0].second, 0});
    

    for(const auto& rule : rules) {
       I0.push_back({rule.first, rule.second, 0}); 
    }

    for (const auto& item : I0) {
        string display_rhs = item.rhs;
        display_rhs.insert(item.dot_pos, "•");
        cout << item.lhs << " -> " << display_rhs << endl;
    }


    return 0;
}