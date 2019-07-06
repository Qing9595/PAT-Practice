#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

struct node {
    double amount;
    double price;
};

node mooncake[MAXN];

bool cmp(node x, node y) {
    return x.price > y.price;
}

int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i=0; i<n; i++) {
        scanf("%lf", &mooncake[i].amount);
    }
    for (int i=0; i<n; i++) {
        double x;
        scanf("%lf", &x);
        mooncake[i].price = x / mooncake[i].amount;
    }
    sort(mooncake, mooncake + n, cmp);
    int sell = 0;
    double ans = 0.0d;
    for (int i=0; i<n; i++) {
        if (sell + mooncake[i].amount <= d) {
            sell += mooncake[i].amount;
            ans += mooncake[i].amount * mooncake[i].price;
        }
        else {
            ans += (d - sell) * mooncake[i].price;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}
