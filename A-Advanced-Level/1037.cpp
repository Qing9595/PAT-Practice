#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int nc, np;
int c[MAXN], p[MAXN];
int cpositive = 0, ppositive = 0;
int cz = 0, pz = 0;

bool cmp(int x, int y) {
    if (x >= 0 && y >= 0) {return x > y;}
    if (x < 0 && y < 0) {return x < y;}
    return x > y;
}

int main() {
    scanf("%d", &nc);
    int pos = 0;
    for (int i=0; i<nc; i++) {
        scanf("%d", &c[pos]);
        if (c[pos] > 0) {cpositive++; pos++;}
        else if (c[pos] < 0) {pos++;}
        else {cz++;}
    }
    nc -= cz;
    scanf("%d", &np);
    pos = 0;
    for (int i=0; i<np; i++) {
        scanf("%d", &p[pos]);
        if (p[pos] > 0) {ppositive++; pos++;}
        else if (p[pos] < 0) {pos++;}
        else {pz++;}
    }
    np -= pz;
    sort(c, c + nc, cmp);
    sort(p, p + np, cmp);
    int ans = 0;
    int p1 = 0, p2 = 0;
    while (p1 < cpositive && p2 < ppositive) {
        ans += c[p1] * p[p2];
        p1++;
        p2++;
    }
    p1 = cpositive;
    p2 = ppositive;
    while (p1 < nc && p2 < np) {
        ans += c[p1] * p[p2];
        p1++;
        p2++;
    }
    printf("%d", ans);
    return 0;
}
