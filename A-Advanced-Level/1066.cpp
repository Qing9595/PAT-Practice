#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *lchild, *rchild;
};

node* ll_rotate(node *p) {
    node *lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
    return p;
}

node* rr_rotate(node *p) {
    node *rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
    return p;
}

node* lr_rotate(node *p) {
    node *q = p->lchild;
    node *r = q->rchild;
    q->rchild = r->lchild;
    p->lchild = r->rchild;
    r->lchild = q;
    r->rchild = p;
    p = r;
    return p;
}

node* rl_rotate(node *p) {
    node *q = p->rchild;
    node *r = q->lchild;
    q->lchild = r->rchild;
    p->rchild = r->lchild;
    r->rchild = q;
    r->lchild = p;
    p = r;
    return p;
}

int depth(node *p) {
    if (p == NULL) return 0;
    return max(depth(p->lchild), depth(p->rchild)) + 1;
}

node* insertAVL(node *&t, int val) {
    if (t == NULL) {
        t = new node;
        t->data = val;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if (t->data > val) {
        t->lchild = insertAVL(t->lchild, val);
        int bf = depth(t->lchild) - depth(t->rchild);
        if (bf > 1) {
            if (val < t->lchild->data) {
                t = ll_rotate(t);
            } else {
                t = lr_rotate(t);
            }
        }
        return t;
    }
    if (t->data < val) {
        t->rchild = insertAVL(t->rchild, val);
        int bf = depth(t->rchild) - depth(t->lchild);
        if (bf > 1) {
            if (val > t->rchild->data) {
                t = rr_rotate(t);
            } else {
                t = rl_rotate(t);
            }
        }
        return t;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    node *t = NULL;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        insertAVL(t, x);
    }
    printf("%d\n", t->data);
    return 0;
}
