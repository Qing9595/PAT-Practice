#include <bits/stdc++.h>
using namespace std;

struct node {
    int level;
    double amount;
    set<int> child;
};

static int n;
static double p, r;
static node* t;
static double* price;

inline double level_order(int ptr) {
    double res = 0;
    t[ptr].level = 0;
    queue<int> q;
    q.push(ptr);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        set<int>::iterator iter;
        for (iter=t[tmp].child.begin(); iter!=t[tmp].child.end(); iter++) {
            q.push(*iter);
            t[*iter].level = t[tmp].level + 1;
        }
        if (t[tmp].child.empty()) {
            // res += p * pow(1 + 0.01 * r, t[tmp].level) * t[tmp].amount;
            res += price[t[tmp].level] * t[tmp].amount;
        }
    }
    return res;
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    t = new node[n];
    price = new double[n];
    price[0] = p;
    for (int i=1; i<n; i++) {
        price[i] = price[i-1] * (1 + 0.01 * r);
    }
    for (int i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        if (k != 0) {
            // t[i].amount = 0;
            for (int j=0; j<k; j++) {
                int x;
                scanf("%d", &x);
                t[i].child.insert(x);
            }
        }
        else {
            double x;
            scanf("%lf", &x);
            t[i].amount = x;
        }
    }
    printf("%.1lf\n", level_order(0));
    return 0;
}
