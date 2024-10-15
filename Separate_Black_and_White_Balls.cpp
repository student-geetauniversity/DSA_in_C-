#include<bits/stdc++.h>
using namespace std;

long long minimumSteps(string s) {
    long long swap = 0;
    int black = 0; 
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') 
            swap += (long long) black; 
        else
            black++; 
    }
    return swap;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Minimum number of swaps: " << minimumSteps(s) << endl;
    
    return 0;
}
