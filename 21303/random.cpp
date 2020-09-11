#include <cstdio>
#include <time.h>
#include <algorithm>
int l;
char buff[100];
int tot = -1;
void out(int cnt) {
    if (l >=100) return;
    bool b = false;
    if (rand() & 1) b = true;
    l+=2;
    printf("(");
    if(b) buff[++tot] = '(';
    if(cnt <= 10 && rand() & 1) out(++cnt);
    printf(")");
    if(b) buff[++tot] = ')';
}

int main() {
    srand(time(0));
    while(l < 85) out(0);
    printf("\n%s", buff);
}