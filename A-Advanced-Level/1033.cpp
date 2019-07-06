#include <bits/stdc++.h>
using namespace std;
#define MAXN 501
#define INF 0x7FFFFFFF

struct node {
    double price;
    double dist;
};

node station[MAXN];
double c, d, avg;
int n;

bool cmp(node x, node y) {
    return x.dist < y.dist;
}

int main() {
    scanf("%lf%lf%lf%d", &c, &d, &avg, &n);
    for (int i=0; i<n; i++) {
        scanf("%lf%lf", &station[i].price, &station[i].dist);
    }
    station[n].price = 0.0d;
    station[n].dist = d;
    sort(station, station + n, cmp);
    if (station[0].dist != 0) {
        printf("The maximum travel distance = 0.00");
    }
    else {
        int now = 0;
        double ans = 0.0d;
        double tank = 0.0d;
        double maxdist = c * avg;
        while (now < n) {
            int k = -1;
            double minprice = INF;
            for (int i=now+1; i<=n; i++) {
                if (station[i].dist - station[now].dist <= maxdist) {
                    if (station[i].price < minprice) {
                        minprice = station[i].price;
                        k = i;
                        if (minprice < station[now].price) {break;}
                    }
                }
                else {break;}
            }
            if (k == -1) {break;}
            double need = (station[k].dist - station[now].dist) / avg;
            if (minprice < station[now].price) {
                if (tank < need) {
                    ans += (need - tank) * station[now].price;
                    tank = 0;
                }
                else {
                    tank -= need;
                }
            }
            else {
                ans += (c - tank) * station[now].price;
                tank = c - need;
            }
            now = k;
        }
        if (now == n) {printf("%.2lf", ans);}
        else {printf("The maximum travel distance = %.2lf", station[now].dist + maxdist);}
    }
    return 0;
}
