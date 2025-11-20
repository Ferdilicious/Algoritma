#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool cekValiditas(string ekspresi) {
    stack<char> s;

    for (char c : ekspresi) {
        
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }

        
        else if (c == ')' || c == ']' || c == '}') {
            
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            
            if (!isMatching(top, c)) return false;
        }
    }


    return s.empty();
}

int main() {
    string ekspresi;

    cout << "Masukkan ekspresi: ";
    getline(cin, ekspresi);

    if (cekValiditas(ekspresi))
        cout << "Valid\n";
    else
        cout << "Tidak Valid\n";

    return 0;
}
