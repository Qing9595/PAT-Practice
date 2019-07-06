#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

int pre[MAXN], post[MAXN];
bool uniqueTree = true;
vector<int> order;

struct node {
    int val;
    node *lc, *rc;
};

void in_order(node *t) {
    if (t != NULL) {
        in_order(t->lc);
        order.push_back(t->val);
        in_order(t->rc);
    }
    return;
}

void print_ans() {
    for (int i=0; i<order.size()-1; i++) {
        printf("%d ", order[i]);
    }
    printf("%d", order[order.size()-1]);
    return;
}

void create_tree(node *t, int preL, int preR, int postL, int postR) {
    int data = pre[preL];
    int
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &post[i]);
    }
    node *tree;

    return 0;
}
