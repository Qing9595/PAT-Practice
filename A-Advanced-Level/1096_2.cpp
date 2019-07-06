#include <bits/stdc++.h>
using namespace std;
#define LL long long

map<pair<int, int>, LL> m;

inline bool is_prime(LL n) {
    LL sqrtN = sqrt(n);
    for (LL i=2; i<=sqrtN; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

inline LL minn(LL n) {
    for (LL i=2; i<n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 0;
}

inline void init() {
    m[pair<int, int>(2, 2)] = 2;
    for (int i=3; i<=13; i++) {
        m[pair<int, int>(2, i)] = m[pair<int, int>(2, i-1)] * i;
    }
    for (int i=3; i<=13; i++) {
        for (int j=i; j<=13; j++) {
            m[pair<int, int>(i, j)] = m[pair<int, int>(i-1, j)] / (i-1);
        }
    }
    return;
}

int main() {
    init();
    LL n;
    scanf("%lld", &n);
    int i = 13, j = 13;
    int ansi = 1, ansj = 1;
    while (true) {
        LL tmp = m[pair<int, int>(i, j)];
        if (n % tmp == 0) {
            ansi = i;
            ansj = j;
        }
        if (i == 2 && j == 13) {
            break;
        }
        i--;
        j--;
        if (i <= 1) {
            i = 13 - j;
            j = 13;
        }
    }

    if (ansi != ansj) {
        printf("%d\n", ansj - ansi + 1);
        for (int i=ansi; i<ansj; i++) {
            printf("%d*", i);
        }
        printf("%d\n", ansj);
    }
    else {
        if (is_prime(n)) {
            printf("1\n%lld\n", n);
        }
        else {
            printf("1\n%lld\n", minn(n));
        }
    }

    return 0;
}
