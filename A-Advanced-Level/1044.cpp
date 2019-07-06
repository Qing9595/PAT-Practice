#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int n, m;
int a[MAXN];
int sum[MAXN];
map<int, int> fit;
int minn = INT_MAX;

int binary(int start, int low, int high) {
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int cmp = sum[mid] - sum[start - 1];
        if (cmp == m) return mid;
        if (cmp < m) low = mid + 1;
        else high = mid - 1;
    }
    int x = sum[mid] - sum[start - 1];
    if (x > m) {
        minn = min(minn, x);
    }
    return -1;
}

int my_upper_bound(int start, int low, int high) {
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int cmp = sum[mid] - sum[start - 1];
        if (cmp == minn) return mid;
        if (cmp < minn) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    int sumx = 0;
    sum[0] = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sumx;
        sumx += a[i];
    }
    for (int i=1; i<=n; i++) {
        int j = binary(i, i, n);
        if (j != -1) {fit.insert(pair<int, int>(i, j));}
    }
    if (!fit.empty()) {
        map<int, int>::iterator iter;
        for (iter=fit.begin(); iter!=fit.end(); iter++) {
            printf("%d-%d\n", iter->first, iter->second);
        }
    }
    else {
        for (int i=1; i<=n; i++) {
            int j = my_upper_bound(i, i, n);
            if (j != -1) {fit.insert(pair<int, int>(i, j));}
        }
        map<int, int>::iterator iter;
        for (iter=fit.begin(); iter!=fit.end(); iter++) {
            printf("%d-%d\n", iter->first, iter->second);
        }
    }
    return 0;
}
