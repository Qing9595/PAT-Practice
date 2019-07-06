#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    int height;
};

bool cmp(node x, node y) {
    if (x.height == y.height) {
        return x.name < y.name;
    }
    return x.height > y.height;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    node person[n];
    for (int i=0; i<n; i++) {
        cin >> person[i].name >> person[i].height;
    }
    sort(person, person+n, cmp);
    int personCnt = 0;
    for (int i=0; i<k; i++) {
        int rowCnt = 0;
        if (i == 0) {
            rowCnt = n % k + n / k;
        }
        else {
            rowCnt = n / k;
        }
        string temp[rowCnt];
        for (int j=0; j<rowCnt; j++) {
            temp[rowCnt/2+int(pow(-1,j)*(j+1)/2)] = person[personCnt++].name;
        }
        for (int j=0; j<rowCnt - 1; j++) {
            cout << temp[j] << ' ';
        }
        cout << temp[rowCnt - 1] << endl;
    }
    return 0;
}
