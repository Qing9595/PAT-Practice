#include <bits/stdc++.h>
using namespace std;

const int MAX_COU = 2501;
const int MAX_STU = 26 * 26 * 26 * 10;
int n, k;

vector<int> course[MAX_COU];
char student[MAX_STU][5];

bool cmp(int x, int y) {
    return strcmp(student[x], student[y]) < 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        int num;
        scanf("%s%d", &student[i], &num);
        while (num--) {
            int x;
            scanf("%d", &x);
            course[x].push_back(i);
        }
    }
    for (int i=1; i<=k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (int j=0; j<course[i].size(); j++) {
            printf("%s\n", student[course[i][j]]);
        }
    }
    return 0;
}
