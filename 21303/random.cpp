#include <cstdio>
#include <time.h>
#include <algorithm>
int l;
void out(int cnt) {
    if (l >=100) return;
    l+=2;
    printf("(");
    if(cnt <= 10 && rand() & 1) out(++cnt);
    printf(")");
}

int main() {
    srand(time(0));
    while(l < 85) out(0);
}