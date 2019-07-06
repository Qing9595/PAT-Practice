#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int p[MAXN];
int part[MAXN];
set<int> person_hobby[MAXN];

void init() {
    for (int i=0; i<MAXN; i++) {
        p[i] = i;
        part[i] = 0;
    }
}

int set_find(int x) {
    int ans = x;
    while (p[ans] != ans) {
        ans = p[ans];
    }
    return ans;
}

void set_join(int x, int y) {
    int fx = set_find(x);
    int fy = set_find(y);
    if (fx != fy) {
        p[fx] = fy;
    }
}

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int k;
        scanf("%d:", &k);
        int first;
        for (int j=0; j<k; j++) {
            int x;
            scanf("%d", &x);
            person_hobby[i].insert(x);
            if (j == 0) {
                first = x;
            }
            else {
                set_join(first, x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        set<int>::iterator iter = person_hobby[i].begin();
        part[set_find(*iter)]++;
    }
    vector<int> ans;
    for (int i=0; i<MAXN; i++) {
        if (part[i] != 0) {
            ans.push_back(part[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i=0; i<ans.size()-1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d", ans[ans.size()-1]);
    return 0;
}
