/** Binary Search **/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int n, m;
int a[MAXN];

int binary(int low, int high) {
    int start = low - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = a[mid] + a[start];
        if (cmp == m) return mid;
        if (cmp < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i=0; i<n; i++) {
        int x = binary(i + 1, n - 1);
        if (x != -1) {
            printf("%d %d\n", a[i], a[x]);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
