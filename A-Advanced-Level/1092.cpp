#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

multiset<char> s;
char s1[MAXN], s2[MAXN];
int len1, len2;

int main() {
    scanf("%s", &s1);
    scanf("%s", &s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i=0; i<len1; i++) {
        s.insert(s1[i]);
    }
    bool flag = true;
    int cnt = 0;
    for (int i=0; i<len2; i++) {
        multiset<char>::iterator iter;
        iter = s.find(s2[i]);
        if (iter != s.end()) {
            s.erase(iter);
        }
        else {
            cnt++;
            flag = false;
        }
    }
    if (flag) {
        printf("Yes %d", len1 - len2);
    }
    else {
        printf("No %d", cnt);
    }
    return 0;
}
