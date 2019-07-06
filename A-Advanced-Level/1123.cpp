#include <bits/stdc++.h>
using namespace std;

vector<int> bitree;
vector<bool> is_leaf;

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
    if (p == NULL) {
        return -1;
    }
    else {
        int nlDepth = depth(p->lchild);
        int nrDepth = depth(p->rchild);
        return (max(nlDepth, nrDepth) + 1);
    }
}

node* insertAVL(node *&t, int val) {
    if (t == NULL) {
        // cout << "case - new" << endl;
        t = new node;
        t->data = val;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if (t->data > val) {
        // cout << "case - left" << endl;
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
        // cout << "case - right" << endl;
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
}

int level_order(node *t) {
    bool flag = true;
    int cnt = 0, index = 0;
    queue<node*> q;
    q.push(t);
    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        if (p->lchild != NULL) {
            q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            q.push(p->rchild);
        }
        if (flag && ((p->lchild == NULL && p->rchild == NULL) || (p->lchild != NULL && p->rchild == NULL))) {
            flag = false;
            index = cnt;
        }
        if (p->lchild == NULL && p->rchild == NULL) {
            is_leaf.push_back(true);
        }
        else {
            is_leaf.push_back(false);
        }
        bitree.push_back(p->data);
        cnt++;
    }
    return index;
}

bool is_cbt(int index) {
    bool flag = false;
    index++;
    for (; index<is_leaf.size(); index++) {
        if (!is_leaf[index]) {
            return false;
        }
    }
    return true;
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
    int index = level_order(t);
    for (int i=0; i<bitree.size()-1; i++) {
        printf("%d ", bitree[i]);
    }
    printf("%d\n", bitree[bitree.size()-1]);
    if (is_cbt(index)) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}
