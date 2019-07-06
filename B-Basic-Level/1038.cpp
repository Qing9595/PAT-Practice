#include <bits/stdc++.h>
using namespace std;

int a[101];

void init() {
    memset(a, 0, sizeof(a));
    return;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int k;
    scanf("%d", &k);
    for (int i=0; i<k-1; i++) {
        int x;
        scanf("%d", &x);
        printf("%d ", a[x]);
    }
    int x;
    scanf("%d", &x);
    printf("%d", a[x]);
    return 0;
}
