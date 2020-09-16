// nowcoder_oi_advance/21303/21302.cpp
// https://ac.nowcoder.com/acm/problem/21303
// Created by learntocode1024 on Sep 16 2020.
// AC
#include <cstdio>
#include <memory.h>
#define MOD % (int)(1e9+7)
char num[50];
int dp[51][3];
int main() {
    scanf("%s", num);
    int size = strlen(num);
    for (int i = 1; i <= size; ++i) {
        int curr = (num[i - 1] - '0') % 3;
        dp[i][curr] = (dp[i - 1][curr] + dp[i - 1][0] + 1)MOD;
        dp[i][(curr + 1) % 3] = (dp[i - 1][(curr + 1) % 3] + dp[i - 1][1])MOD;
        dp[i][(curr + 2) % 3] = (dp[i - 1][(curr + 2) % 3] + dp[i - 1][2])MOD;
    }
    printf("%d", dp[size][0]MOD);
    return 0;
}