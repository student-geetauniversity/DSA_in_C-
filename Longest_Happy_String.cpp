#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c) {
    string ans = "";

    while (a > 0 || b > 0 || c > 0) {
        int maxi = max({a, b, c});
        if (maxi == a) {
            if (a >= 2 && (ans.empty() || ans.back() != 'a')) {
                ans += "aa";
                a -= 2;
                if (b > 0) {
                    ans += 'b';
                    b--;
                } else if (c > 0) {
                    ans += 'c';
                    c--;
                } else break;
            } else if (a > 0) {
                ans += 'a';
                a--;
            } else break;
        } else if (maxi == b) {
            if (b >= 2 && (ans.empty() || ans.back() != 'b')) {
                ans += "bb";
                b -= 2;
                if (a > 0) {
                    ans += 'a';
                    a--;
                } else if (c > 0) {
                    ans += 'c';
                    c--;
                } else break;
            } else if (b > 0) {
                ans += 'b';
                b--;
            } else break;
        } else if (maxi == c) {
            if (c >= 2 && (ans.empty() || ans.back() != 'c')) {
                ans += "cc";
                c -= 2;
                if (b > 0) {
                    ans += 'b';
                    b--;
                } else if (a > 0) {
                    ans += 'a';
                    a--;
                } else break;
            } else if (c > 0) {
                ans += 'c';
                c--;
            } else break;
        } else break;
    }
    return ans;
}

int main() {
    int a, b, c;
    cout << "Enter value of a: ";
    cin >> a;
     cout << "Enter value of b: ";
    cin >> b;
     cout << "Enter value of c: ";
    cin >> c;
    
    string result = longestDiverseString(a, b, c);
    cout << "Longest diverse string: " << result << endl;

    return 0;
}
