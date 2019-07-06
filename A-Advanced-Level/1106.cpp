#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct node {
    set<int> child;
};

node t[MAXN];
int leaves = 0, level = 0;

void level_order() {
    int curLevelCnt = 1, nextLevelCnt = 0;
    bool flag = false;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        curLevelCnt--;
        if (!flag && !t[p].child.empty()) {
            set<int>::iterator iter;
            for (iter=t[p].child.begin(); iter!=t[p].child.end(); iter++) {
                q.push(*iter);
            }
            nextLevelCnt += t[p].child.size();
        }
        else if (!flag && t[p].child.empty()) {
            flag = true;
            leaves++;
        }
        else if (flag && t[p].child.empty()) {
            leaves++;
        }
        if (flag && curLevelCnt == 0) {
            break;
        }
        if (curLevelCnt == 0) {
            level++;
            curLevelCnt = nextLevelCnt;
            nextLevelCnt = 0;
        }
    }
}

int main() {
    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            t[i].child.insert(x);
        }
    }
    level_order();
    double cost = p;
    for (int i=0; i<level; i++) {
        cost *= (1 + 0.01 * r);
    }
    printf("%.4lf %d", cost, leaves);
    return 0;
}
