#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define LL long long

int n, p;
int a[MAXN];

int main() {
    scanf("%d%d", &n, &p);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int p1 = 0, p2 = 0;
    int ans = 1;
    while (p2 < n) {
        if ((LL)(a[p2]) <= (LL)(a[p1]) * (LL)(p)) {
            p2++;
            ans = p2 - p1;
        }
        else {
            p1++;
            p2++;
        }
    }
    printf("%d", ans);
    return 0;
}
