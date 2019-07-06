#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double input = 0.0, sum = 0.0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%lf", &input);
        sum += input * i * (n - i + 1);
    }
    printf("%.2lf", sum);
    return 0;
}
