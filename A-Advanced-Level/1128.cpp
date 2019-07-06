#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int a[MAXN];
bool hashTable[MAXN];

bool judge(int n) {
    memset(hashTable, 0, sizeof(hashTable));
    for (int i=1; i<=n; i++) {
        hashTable[a[i]] = true;
    }
    for (int i=1; i<=n; i++) {
        if (!hashTable[i]) {return false;}
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (abs(i - j) == abs(a[i] - a[j])) {return false;}
        }
    }
    return true;
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        if (judge(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
