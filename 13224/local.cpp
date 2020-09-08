// nowcoder_oi_advance/13224.cpp
// https://ac.nowcoder.com/acm/problem/13224
// Created by learntocode1024 on Sep 08 2020.
// 
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#define MX 10
#define inf 0x3F3F3F3F
using std::vector;
using std::string;
using std::queue;

int n;
vector<string> stat(MX);
int a[MX];
int b[MX];
bool ring = false;
queue<int> q;

bool bfs() {
    stat[0]="a";
    q.push(0);
    while (q.size()) {
        int curr = q.front(); q.pop();
        for (int i  = 0, next = a[curr]; i < 2; i++, next = b[curr]) {
            if (next == -1) continue;
            string temp = stat[curr] + ((i==0)?"a":"b");
            bool ispref = stat[next] == temp.substr(0, stat[next].size());
            if (stat[next].size() && ispref) {
                if (temp[stat[next].size()] == 'a') ring = true;
                continue;
            }
            if (!stat[next].size() || stat[curr] < stat[next]) {
                stat[next] = temp;
                q.push(next);
            }
            if (next == n - 1) return true;
        }
    }
    return false;
}

int main() {
    // input
    int temp;
    scanf("%d", &n);
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) a[i] = temp;
        else a[i] = -1;
    }
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) b[i] = temp;
        else b[i] = -1;
    }
    // Solution
    if (bfs()) {
        string ans = stat[n - 1].substr(1);
        if (!ring) std::cout << ans;
        else {
            printf("Infinity!");
        }
    } else printf("No solution!");
    return 0;
}