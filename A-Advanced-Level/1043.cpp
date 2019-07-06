#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *lc, *rc;
};

static node *t1 = NULL, *t2 = NULL;
static vector<int> origin, pre1, pre2, post;

void build_bst(node *&p, const int &x) {
    if (p == NULL) {
        p = new node;
        p->val = x;
        p->lc = NULL;
        p->rc = NULL;
        return;
    }
    if (p->val <= x) {
        build_bst(p->rc, x);
    }
    else {
        build_bst(p->lc, x);
    }
    return;
}

void mirror(node *&p) {
    if (p != NULL) {
        mirror(p->lc);
        mirror(p->rc);
        swap(p->lc, p->rc);
    }
    return;
}

void pre_travel(node *p, vector<int> &v) {
    if (p != NULL) {
        v.push_back(p->val);
        pre_travel(p->lc, v);
        pre_travel(p->rc, v);
    }
    return;
}

void post_travel(node *p, vector<int> &v) {
    if (p != NULL) {
        post_travel(p->lc, v);
        post_travel(p->rc, v);
        v.push_back(p->val);
    }
    return;
}

inline void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        if (i != v.size() - 1) {
            printf("%d ", v[i]);
        }
        else {
            printf("%d\n", v[i]);
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        origin.push_back(x);
        build_bst(t1, x);
        build_bst(t2, x);
    }
    mirror(t2);
    pre_travel(t1, pre1);
    pre_travel(t2, pre2);
    if (origin == pre1) {
        printf("YES\n");
        post_travel(t1, post);
        print(post);
    }
    else if (origin == pre2) {
        printf("YES\n");
        post_travel(t2, post);
        print(post);
    }
    else {
        printf("NO\n");
    }
    return 0;
}
