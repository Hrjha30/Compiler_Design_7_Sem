#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Function to find terminals and non-terminals
void findTerminalsAndNonTerminals(const vector<string>& grammar, set<char>& terminals, set<char>& nonTerminals) {
    for (const string& production : grammar) {
        // The first character of each production is assumed to be a non-terminal
        nonTerminals.insert(production[0]);

        for (char symbol : production) {
            // Check if the symbol is an uppercase letter (non-terminal) or not
            if (isupper(symbol)) {
                nonTerminals.insert(symbol);
            } else if (isalnum(symbol) && !isdigit(symbol)) {
                // Check if the symbol is an alphabet (terminal)
                terminals.insert(symbol);
            }
        }
    }
}

int main() {
    vector<string> grammar;
    string production;
    
    cout << "Enter grammar rules (type 'exit' to finish input):\n";
    while (true) {
        cout << "Production: ";
        getline(cin, production);
        if (production == "exit") {
            break;
        }
        grammar.push_back(production);
    }

    set<char> terminals;
    set<char> nonTerminals;

    findTerminalsAndNonTerminals(grammar, terminals, nonTerminals);

    cout << "Terminals: ";
    for (char terminal : terminals) {
        cout << terminal << " ";
    }
    cout << endl;

    cout << "Non-terminals: ";
    for (char nonTerminal : nonTerminals) {
        cout << nonTerminal << " ";
    }
    cout << endl;

    return 0;
}



/*input
Production: S -> AB
Production: A -> aA | ε
Production: B -> bB | c
Production: exit*/

/*output
Terminals: a b c 
Non-terminals: A B S 
*/