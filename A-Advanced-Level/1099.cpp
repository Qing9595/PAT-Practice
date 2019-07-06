#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

struct node {
    int data;
    int lc, rc;
};

node t[MAXN];
int a[MAXN];
int ind = 0;
int ans[MAXN];

void in_order(int x) {
    if (x != -1) {
        in_order(t[x].lc);
        t[x].data = a[ind++];
        in_order(t[x].rc);
    }
}

void level_order(int x) {
    int i = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        ans[i++] = t[p].data;
        if (t[p].lc != -1) {
            q.push(t[p].lc);
        }
        if (t[p].rc != -1) {
            q.push(t[p].rc);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        t[i].lc = x;
        t[i].rc = y;
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    in_order(0);
    level_order(0);
    for (int i=0; i<n-1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d", ans[n-1]);
    return 0;
}
