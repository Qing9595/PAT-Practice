#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

int cnt[10001];
int a[100000];
set<int> uni;

int main() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        cnt[x]++;
    }
    for (int i=0; i<10001; i++) {
        if (cnt[i] == 1) {
            uni.insert(i);
        }
    }
    if (uni.empty()) {
        printf("None");
    }
    else {
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (uni.find(a[i]) != uni.end()) {
                ans = a[i];
                break;
            }
        }
        printf("%d", ans);
    }
    return 0;
}
