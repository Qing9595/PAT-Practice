#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int bird[MAXN];
int cnt_union = 0;

inline void init() {
    for (int i=1; i<MAXN; i++) {
        bird[i] = i;
    }
    return;
}

inline int set_find(int x) {
    int ans = x;
    while (bird[ans] != ans) {
        ans = bird[ans];
    }
    return ans;
}

inline void set_join(int x, int y) {
    cnt_union++;
    int fx = set_find(x);
    int fy = set_find(y);
    if (fx != fy) {
        bird[fx] = fy;
    }
    return;
}

int main() {
    init();
    int n, cnt_birds = 1;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);
        int first;
        for (int i=0; i<k; i++) {
            int x;
            scanf("%d", &x);
            if (i == 0) {
                first = x;
            }
            else {
                set_join(first, x);
            }
            cnt_birds = max(cnt_birds, x);
        }
    }
    printf("%d %d\n", cnt_birds - cnt_union, cnt_birds);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (set_find(x) == set_find(y)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
