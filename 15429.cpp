// nowcoder_oi_advance/15429.cpp
// https://ac.nowcoder.com/acm/problem/15429
// Created by learntocode1024 on Sep 02 2020.
// 

#include <cstdio>
#define MX 1000001
typedef long long ll;

int m, n, k;
int a[MX];
ll s[MX];

int main() {
    /******* pre-processing *******/
    scanf("%d %d %d", &n, &m, &k);
    for (register int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }
    /******* answering *******/
    int l, r;
    for (int j = 0; j < m; ++j) { // m times
        scanf("%d %d", &l, &r);
        int cnt;
        // solve
        for (cnt = 0; l <= r; ++cnt) {
            int ans = l - 1, step = 1;
            ll val = 0;
            while (step) {
                if (ans + step <= r && val + s[ans + step] - s[ans] <= k) {
                    val += s[ans + step] - s[ans];
                    ans += step;
                    step <<= 1;
                } else step >>= 1;
            }
            if (ans == l - 1) {
                printf("Chtholly\n");
                break;
            }
            l = ans + 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}