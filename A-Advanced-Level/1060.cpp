#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
string numa = "", numb = "";
int expa = 0, expb = 0;

string deal(string s) {
    int pos = 0;
    for (pos=0; pos<s.size(); pos++) {
        if (s[pos] != '0') {break;}
    }
    s = s.substr(pos);
    pos = s.find('.');
    if (pos != string::npos) {
        for (pos=s.size()-1; pos>=0; pos--) {
            if (s[pos] != '0') {break;}
        }
        s = s.substr(0, pos + 1);
    }
    else {s += ".";}
    return s;
}

int find_start(string s) {
    int res = -1;
    if (s[0] != '.') return 0;
    for (int i=1; i<s.size(); i++) {
        if (s[i] != '0') {res = i; break;}
    }
    return res;
}

int main() {
    scanf("%d", &n);
    cin >> a >> b;
    a = deal(a);
    b = deal(b);

    int pos = find_start(a);
    for (int i=0; i<n; ) {
        if (pos < a.size() && a[pos] != '.') {numa += a[pos]; i++;}
        else if (pos >= a.size()) {numa += "0"; i++;}
        pos++;
    }
    expa = a.find('.') - find_start(a);
    if (expa < 0) {expa++;}
    if (a == ".") {expa = 0;}

    pos = find_start(b);
    for (int i=0; i<n; ) {
        if (pos < b.size() && b[pos] != '.') {numb += b[pos]; i++;}
        else if (pos >= b.size()) {numb += "0"; i++;}
        pos++;
    }
    expb = b.find('.') - find_start(b);
    if (expb < 0) {expb++;}
    if (b == ".") {expb = 0;}

    if (numa == numb && expa == expb) {
        printf("YES ");
        cout << "0." << numa << "*10^" << expa << endl;
    }
    else {
        printf("NO ");
        cout << "0." << numa << "*10^" << expa;
        cout << " ";
        cout << "0." << numb << "*10^" << expb;
        cout << endl;
    }
    return 0;
}
