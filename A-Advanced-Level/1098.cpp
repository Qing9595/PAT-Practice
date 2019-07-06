#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

static int n;
static int a[MAXN], b[MAXN], c[MAXN];

inline void output(int n, int A[]) {
    for (int i=0; i<n-1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);
    return;
}

inline bool cmp(int len, int A[], int B[]) {
    for (int i=0; i<len; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

inline void insertion(int i, int len, int A[]) {
    for ( ; i > 0; i--) {
        if (A[i-1] > A[i]) {
            swap(A[i-1], A[i]);
        }
    }
    return;
}

inline void heap(int i, int len, int A[]) {
    pop_heap(A, A+len-i);
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }
    bool flag = false;
    int i;
    for (i=1; i<n; i++) {
        insertion(i, n, a);
        if (cmp(n, a, b)) {
            flag = true;
            break;
        }
    }
    if (flag) {
        insertion(i+1, n, a);
        printf("Insertion Sort\n");
        output(n, a);
    }
    else {
        printf("Heap Sort\n");
        make_heap(c, c+n);
        for (i=0; i<n; i++) {
            heap(i, n, c);
            if (cmp(n, b, c)) {
                break;
            }
        }
        heap(i+1, n, c);
        output(n, c);
    }
    return 0;
}
