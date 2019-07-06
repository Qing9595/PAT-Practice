#include <bits/stdc++.h>
using namespace std;
#define MAXN 201

bool graph[MAXN][MAXN];

void init() {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            graph[i][j] = false;
        }
    }
}

bool is_path(int a[], int len) {
    for (int i=1; i<len; i++) {
        if (!graph[a[i-1]][a[i]]) {
            return false;
        }
    }
    sort(a, a+len-1);
    for (int i=0; i<len-1; i++) {
        if (a[i] != i+1) {
            return false;
        }
    }
    return true;
}

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x][y] = true;
        graph[y][x] = true;
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int cnt;
        scanf("%d", &cnt);
        int a[cnt];
        for (int i=0; i<cnt; i++) {
            scanf("%d", &a[i]);
        }
        if (cnt != n + 1 || a[0] != a[cnt - 1]) {
            printf("NO\n");
        }
        else {
            if (is_path(a, cnt)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
