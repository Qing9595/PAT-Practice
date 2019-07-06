#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26 * 26 * 26 * 10;
int n, k;

set<int> sc[MAXN];

inline int get_id(char name[]) {
    int res = 0;
    for (int i=0; i<3; i++) {
        res = (name[i] - 'A') + res * 26;
    }
    res = res * 10 + (name[3] - '0');
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<k; i++) {
        int x, num;
        scanf("%d%d", &x, &num);
        while (num--) {
            char name[5];
            scanf("%s", &name);
            int id = get_id(name);
            sc[id].insert(x);
        }
    }
    while (n--) {
        char name[5];
        scanf("%s", &name);
        int id = get_id(name);
        printf("%s %d", name, sc[id].size());
        set<int>::iterator iter;
        for (iter=sc[id].begin(); iter!=sc[id].end(); iter++) {
            printf(" %d", *iter);
        }
        printf("\n");
    }
    return 0;
}
