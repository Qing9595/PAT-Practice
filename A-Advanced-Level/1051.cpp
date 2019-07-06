#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int m, n, k;
stack<int> s;
int a[MAXN];

bool judge() {
    while (!s.empty()) {
        s.pop();
    }
    int cur = 1;
    for (int i=1; i<=n; i++) {
        s.push(i);
        if (s.size() > m) return false;
        while (!s.empty() && a[cur] == s.top()) {
            s.pop();
            cur++;
        }
    }
    return (s.empty() ? true : false);
}


int main() {
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        if (judge()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
