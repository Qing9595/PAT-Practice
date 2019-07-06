#include <bits/stdc++.h>
using namespace std;

int height;
int x = 0, y = 0;

struct node {
    int val;
    node *lc, *rc;
};

inline void build(node *&t, int x) {
    if (t == NULL) {
        t = new node;
        t->val = x;
        t->lc = NULL;
        t->rc = NULL;
    }
    else if (t->val < x) {
        build(t->rc, x);
    }
    else {
        build(t->lc, x);
    }
}

inline int depth(node *t) {
    return (t == NULL ? 0 : max(depth(t->lc) + 1, depth(t->rc) + 1));
}

inline void level_order(node *t) {
    int level = 1;
    int curLevelCnt = 1, nextLevelCnt = 0;
    queue<node*> q;
    q.push(t);
    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        curLevelCnt--;
        if (level == height - 1) {
            x++;
        }
        else if (level == height) {
            y++;
        }
        if (p->lc != NULL) {
            q.push(p->lc);
            nextLevelCnt++;
        }
        if (p->rc != NULL) {
            q.push(p->rc);
            nextLevelCnt++;
        }
        if (curLevelCnt == 0) {
            curLevelCnt = nextLevelCnt;
            nextLevelCnt = 0;
            level++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    node *tree = NULL;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        build(tree, x);
    }
    height = depth(tree);
    level_order(tree);
    printf("%d + %d = %d", y, x, y+x);
    return 0;
}
