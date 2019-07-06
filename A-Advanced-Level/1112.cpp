#include <bits/stdc++.h>
using namespace std;

map<char, bool> flag;
set<char> show, out;

void init() {
    for (char c='a'; c<='z'; c++) {
        flag[c] = true;
    }
    for (char c='0'; c<='9'; c++) {
        flag[c] = true;
    }
    flag['_'] = true;
}

int main() {
    init();
    int k;
    string str;
    scanf("%d", &k);
    cin >> str;
    int cnt = 1;
    show.insert(str[0]);
    for (int i=1; i<str.length(); i++) {
        show.insert(str[i]);
        if (str[i] == str[i-1]) {
            cnt++;
        }
        else {
            if (cnt % k != 0) {
                flag[str[i-1]] = false;
            }
            else {
                if (flag[str[i-1]] == true && show.find(str[i-1]) != show.end() && out.find(str[i-1]) == out.end()) {
                    cout << str[i-1];
                    out.insert(str[i-1]);
                }
            }
            cnt = 1;
        }
    }
    /*
    set<char>::iterator it;
    for (it=show.begin(); it!=show.end(); it++) {
        if (flag[*it] == true) {
            cout << *it;
        }
    }
    */
    printf("\n");
    for (int i=0; i<str.length(); ) {
        if (flag[str[i]] == true) {
            cout << str[i];
            i += k;
        }
        else {
            cout << str[i];
            i++;
        }
    }
    return 0;
}
