#include <bits/stdc++.h>
using namespace std;
#define MAXN 50000

struct node {
    int x, y;
};

node couple[MAXN];
set<int> guest;

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d", &couple[i].x, &couple[i].y);
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int x;
        scanf("%d", &x);
        guest.insert(x);
    }
    for (int i=0; i<n; i++) {
        set<int>::iterator a = guest.find(couple[i].x);
        set<int>::iterator b = guest.find(couple[i].y);
        if (a != guest.end() && b != guest.end() && a != b) {
            guest.erase(couple[i].x);
            guest.erase(couple[i].y);
        }
    }
    int cnt = guest.size();
    if (cnt == 0) {
        printf("0\n");
    }
    else {
        printf("%d\n", cnt);
        set<int>::iterator iter = guest.begin();
        while (iter != guest.end() && cnt != 1) {
            printf("%05d ", *iter);
            iter++;
            cnt--;
        }
        printf("%05d", *iter);
    }
    return 0;
}
