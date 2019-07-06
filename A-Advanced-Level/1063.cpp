#include <bits/stdc++.h>
using namespace std;
#define MAXN 51

set<int> s[MAXN];
int n;

float calc(int x, int y) {
    int union_cnt = s[y].size(), intersection_cnt = 0;
    set<int>::iterator iter;
    for (iter=s[x].begin(); iter!=s[x].end(); iter++) {
        if (s[y].find(*iter) == s[y].end()) {
            union_cnt++;
        }
        else {
            intersection_cnt++;
        }
    }
    return (100.0 * intersection_cnt / union_cnt);
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int k;
        scanf("%d", &k);
        int x;
        while (k--) {
            scanf("%d", &x);
            s[i].insert(x);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        // set<int> intersection_set, union_set;
        // set_intersection(s[x].begin(), s[x].end(), s[y].begin(), s[y].end(), inserter(intersection_set, intersection_set.begin()));
        // set_union(s[x].begin(), s[x].end(), s[y].begin(), s[y].end(), inserter(union_set, union_set.begin()));
        printf("%.1f%%\n", calc(x, y));
    }
    return 0;
}
