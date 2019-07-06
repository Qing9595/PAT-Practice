#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int ans = n;
    for (; ans>0; ans--) {
        if (a[n-ans] > ans) {
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
