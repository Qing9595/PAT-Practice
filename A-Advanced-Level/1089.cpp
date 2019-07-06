#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int n;
int pre[MAXN];
int my[MAXN];
int post[MAXN];

void print_ans(int a[]) {
    for (int i=0; i<n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    return;
}

void insert_sort(int x) {
    while (x > 0 && my[x] < my[x - 1]) {
        swap(my[x], my[x - 1]);
        x--;
    }
    return;
}

void merge_sort(int x) {
    int cnt = pow(2, x) + 1e-5;
    int pos = 0;
    while (pos < n - 1) {
        if (pos + cnt <= n) {
            sort(pre + pos, pre + pos + cnt);
        }
        else {
            sort(pre + pos, pre + n);
            break;
        }
        pos += cnt;
    }
    return;
}

bool my_is_same(int a[]) {
    for (int i=0; i<n; i++) {
        if (a[i] != post[i]) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &pre[i]);
        my[i] = pre[i];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &post[i]);
    }
    bool flag = false;
    int pos;
    for (pos=1; pos<n; pos++) {
        insert_sort(pos);
        if (my_is_same(my)) {
            flag = true;
            break;
        }
    }
    if (flag) {
        printf("Insertion Sort\n");
        insert_sort(pos + 1);
        print_ans(my);
    }
    else {
        printf("Merge Sort\n");
        int pos;
        for (pos=1; pos<n; pos++) {
            merge_sort(pos);
            if (my_is_same(pre)) {
                break;
            }
        }
        merge_sort(pos + 1);
        print_ans(pre);
    }
    return 0;
}
