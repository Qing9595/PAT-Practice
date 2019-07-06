#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MOD 1000000007

char str[MAXN];
int p[MAXN], t[MAXN];
int len = 0;

void init() {
    memset(p, 0, sizeof(p));
    memset(t, 0, sizeof(t));
    return;
}

int main() {
    init();
    scanf("%s", &str);
    len = strlen(str);
    int cnt = 0;
    for (int i=0; i<len; i++) {
        p[i] = cnt;
        if (str[i] == 'P') {
            cnt++;
        }
    }
    cnt = 0;
    for (int i=len-1; i>=0; i--) {
        t[i] = cnt;
        if (str[i] == 'T') {
            cnt++;
        }
    }
    int ans = 0;
    for (int i=0; i<len; i++) {
        if (str[i] == 'A') {
            ans = (ans + p[i] * t[i]) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
