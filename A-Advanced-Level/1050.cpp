#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

char s1[MAXN], s2[MAXN];
int len1 = 0, len2 = 0;
set<char> pass;

int main() {
    gets(s1);
    gets(s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i=0; i<len2; i++) {
        pass.insert(s2[i]);
    }
    for (int i=0; i<len1; i++) {
        if (pass.find(s1[i]) == pass.end()) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}
