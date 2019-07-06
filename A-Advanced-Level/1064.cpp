#include <bits/stdc++.h>
using namespace std;

static int n;
static int *p, *q;
static int cnt = 1;

void in_order(const int &t) {
    if (t <= n) {
        in_order(2 * t);
        q[t] = p[cnt++];
        in_order(2 * t + 1);
    }
    return;
}

int main() {
    scanf("%d", &n);
    p = new int[n + 1];
    for (int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p + 1, p + n + 1);
    q = new int[n + 1];
    in_order(1);
    delete [] p;
    for (int i=1; i<n; i++) {
        printf("%d ", q[i]);
    }
    printf("%d\n", q[n]);
    delete [] q;
    return 0;
}
