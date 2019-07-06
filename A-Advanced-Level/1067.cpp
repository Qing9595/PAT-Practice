#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int a[MAXN];
int n;

int main() {
	scanf("%d", &n);
	int left = 0;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		a[x] = i;
		if (x != i) {left++;}
	}
	if (a[0] == 0) {left++;}
	int pos = 1;
	while (left > 1) {
		if (a[0] == 0) {
			for (; pos<n; pos++) {
				if (a[pos] != pos) {break;}
			}
			swap(a[0], a[pos]);
			cnt++;
		}
		else {
			swap(a[0], a[a[0]]);
			cnt++;
			left--;
		}
	}
	printf("%d", cnt);
	return 0;
}
