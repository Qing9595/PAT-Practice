#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    bool flag;
};

bool cmp(int x, int y) {
    return (x > y);
}

bool is_int(double x) {
    if (double(int(x)) == x) {
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int row = 1, col = 1;
    for (col = int(sqrt(n)); col<n; col++) {
        double temp = double(n) / col;
        if (is_int(temp)) {
            row = int(temp);
            break;
        }
    }
    if (col > row) {
        swap(col, row);
    }
    int a[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n, cmp);
    node ans[row][col];
    int x = 0, y = 0;
    int d = 3; // up, down, left, right = 0, 1, 2, 3
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            ans[i][j].flag = false;
        }
    }
    for (int i=0; i<n; i++) {
        ans[x][y].val = a[i];
        ans[x][y].flag = true;
        switch (d) {
            case 3 : {
                if (y+1 >= col || ans[x][y+1].flag==true) {
                    d = 1;
                    x++;
                }
                else {
                    y++;
                }
            } break;
            case 2 : {
                if (y-1<0 || ans[x][y-1].flag==true) {
                    d = 0;
                    x--;
                }
                else {
                    y--;
                }
            } break;
            case 1 : {
                if (x+1 >= row || ans[x+1][y].flag==true) {
                    d = 2;
                    y--;
                }
                else {
                    x++;
                }
            } break;
            case 0 : {
                if (x-1<0 || ans[x-1][y].flag==true) {
                    d = 3;
                    y++;
                }
                else {
                    x--;
                }
            } break;
        }
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (j != col - 1) {
                printf("%d ", ans[i][j].val);
            }
            else {
                printf("%d\n", ans[i][j].val);
            }
        }

    }
    return 0;
}
