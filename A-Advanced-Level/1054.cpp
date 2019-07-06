#include <bits/stdc++.h>
using namespace std;
#define MAXN 480000

int n;
int a[MAXN];

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    n = x * y;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    printf("%d\n", a[n / 2]);
    return 0;
}
