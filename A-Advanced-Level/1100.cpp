#include <bits/stdc++.h>
using namespace std;

string a[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int n;
    scanf("%d", &n);
    cin.get();
    while (n--) {
        string s;
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9') {
            int i = atoi(s.c_str());
            string x, y;
            x = b[i / 13];
            y = a[i % 13];
            if (x == "tret" && y == "tret") {
                cout << "tret" << endl;
            }
            else if (x == "tret" && y != "tret") {
                cout << y << endl;
            }
            else if (x != "tret" && y == "tret") {
                cout << x << endl;
            }
            else {
                cout << x << ' ' << y << endl;
            }
        }
        else {
            int k;
            for (k=0; k<s.length(); k++) {
                if (s[k] == ' ') {
                    break;
                }
            }
            if (k == s.length()) {
                int i;
                for (i=0; i<13; i++) {
                    if (s == b[i]) {
                        break;
                    }
                }
                if (i < 13) {
                    cout << 13 * i << endl;
                }
                else {
                    for (i=0; i<13; i++) {
                        if (s == a[i]) {
                            break;
                        }
                    }
                    cout << i << endl;
                }
            }
            else {
                string x = s.substr(0, k);
                string y = s.substr(k + 1, s.length());
                int i, j;
                for (i=0; i<13; i++) {
                    if (x == b[i]) {
                        break;
                    }
                }
                for (j=0; j<13; j++) {
                    if (y == a[j]) {
                        break;
                    }
                }
                cout << 13 * i + j << endl;
            }
        }
    }
    return 0;
}
