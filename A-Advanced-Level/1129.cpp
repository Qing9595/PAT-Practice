#include <bits/stdc++.h>
using namespace std;
#define MAXN 50000

static int n, k;


struct node {
    int num;
    int cnt;
};

bool operator < (const node &A, const node &B) {
    if (A.num != B.num) {
        return A.cnt > B.cnt;
    }
    return A.num < B.num;
}

set<node> order;

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        if (i == 0) {
            node p;
            p.num = x;
            p.cnt = 1;
            order.insert(p);
        }
        else {
            printf("%d:", x);
            set<node>::iterator iter;
            int j = 1;
            for (iter=order.begin(); iter!=order.end(); iter++) {
                j++;
                if (j == k) {
                    break;
                }
                printf(" %d", iter->num);
            }
            printf("\n");
            for (iter=order.begin(); iter!=order.end(); iter++) {
                if (iter->num == x) {
                    break;
                }
            }
            if (iter != order.end()) {
                node p;
                p.num = x;
                p.cnt = iter->cnt + 1;
                order.erase(iter);
                order.insert(p);
            }
            else {
                node p;
                p.num = x;
                p.cnt = 1;
                order.insert(p);
            }
        }
    }
    return 0;
}
