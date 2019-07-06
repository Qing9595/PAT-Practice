#include <bits/stdc++.h>
using namespace std;

inline bool is_prime(int x) {
    for (int i=2; i<x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

inline int findlist(int a[], int len, int key) {
    for (int i=1; i<=len; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int ranklist[n+1];
    for (int i=1; i<=n; i++) {
        scanf("%d", &ranklist[i]);
    }
    scanf("%d", &k);
    set<int> check;
    while (k--) {
        int x;
        scanf("%d", &x);
        int index = findlist(ranklist, n, x);
        if (index == 0) {
            printf("%04d: Are you kidding?\n", x);
        }
        else {
            if (check.empty() || check.find(x) == check.end()) {
                check.insert(x);
                if (index == 1) {
                    printf("%04d: Mystery Award\n", x);
                }
                else if (is_prime(index)) {
                    printf("%04d: Minion\n", x);
                }
                else {
                    printf("%04d: Chocolate\n", x);
                }
            }
            else {
                printf("%04d: Checked\n", x);
            }
        }
    }
    return 0;
}
