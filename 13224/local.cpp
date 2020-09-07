#include <cstdio>
#include <algorithm>
#define MX 100005
#define inf 0x3F3F3F3F

int n;
int a[MX];
int b[MX];

int main() {
    // input
    int temp;
    scanf("%d", &n);
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) a[i] = temp;
        else a[i] = inf;
    }
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) b[i] = temp;
        else b[i] = inf;
    }
    // Solution
    
    return 0;
}