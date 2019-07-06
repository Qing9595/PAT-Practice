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
    int ans1, ans2 = 0;
    if (n % 2 == 0) {
        ans1 = 0;
        for (int i=0; i<n/2; i++) {
            ans2 += a[i];
        }
        for (int i=n/2; i<n; i++) {
            ans2 -= a[i];
        }
        ans2 = abs(ans2);
    }
    else {
        ans1 = 1;
        int tmp1 = 0, tmp2 = 0;
        for (int i=0; i<n/2; i++) {
            tmp1 += a[i];
        }
        for (int i=n/2; i<n; i++) {
            tmp1 -= a[i];
        }
        tmp1 = abs(tmp1);
        for (int i=0; i<n/2+1; i++) {
            tmp2 += a[i];
        }
        for (int i=n/2+2; i<n; i++) {
            tmp2 -= a[i];
        }
        tmp2 = abs(tmp2);
        ans2 = max(tmp1, tmp2);
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
