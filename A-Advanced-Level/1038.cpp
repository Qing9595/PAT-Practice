#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

int n;
string a[MAXN];

bool cmp(string x, string y) {
    return x + y < y + x;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    string ans = "";
    for (int i=0; i<n; i++) {
        ans += a[i];
    }
    int pos = 0;
    for (pos=0; pos<ans.length(); pos++) {
        if (ans[pos]!='0') {break;}
    }
    ans = ans.substr(pos);
    if (ans != "") {
        cout << ans;
    }
    else {
        cout << "0";
    }
    return 0;
}
