/** two pointers **/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int n, m;
int a[MAXN];
int p1 = 0, p2 = 0;

void slove() {
    p1 = 0;
    p2 = n - 1;
    while (p1 != p2) {
        int cmp = a[p1] + a[p2];
        if (cmp == m) return;
        if (cmp < m) {p1++;}
        else {p2--;}
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    slove();
    if (p1 == p2) {printf("No Solution\n");}
    else {printf("%d %d\n", a[p1], a[p2]);}
    return 0;
}
