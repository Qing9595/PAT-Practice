#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int n, m;
int a[MAXN], b[MAXN];

int my_merge() {
    int p1 = 0, p2 = 0, ptr = 0;
    int mid = (n + m - 1) / 2;
    int res = 0;
    while (ptr <= mid) {
        if (p1 < n && p2 < m) {
            if (a[p1] >= b[p2]) {res = b[p2++];}
            else {res = a[p1++];}
        }
        else if (p1 == n) {
            res = b[p2++];
        }
        else if (p2 == m) {
            res = a[p1++];
        }
        ptr++;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    printf("%d\n", my_merge());
    return 0;
}
