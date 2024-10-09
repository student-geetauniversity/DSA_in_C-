#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> S;
    int c = 0;
    for (char i : s) {
        if (i == '(')
            S.push(i);
        else {
            if (S.empty())
                c++;
            else
                S.pop();
        }
    }
    return c + S.size();
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = minAddToMakeValid(s);
    cout << "Minimum additions to make the string valid: " << result << endl;
    return 0;
}
