// test data generator for problem 15429

#include <cstdio>
#include <fstream>
#include <iostream>

void generator() {
    unsigned in;
    srand(time(NULL));
    std::cout << "1000000 1000000 1200000000\n";
    for (int i = 0; i < 1000000; ++i) {
        in = rand()%1000000 + 1;
        std::cout << in << " ";
    }
    std::cout << "\n";
    int last;
    for (int i = 0; i < 1000000; ++i) {
        last = rand()%1000000 + 1;
        in = rand()%1000000 + 1;
        if (last > in) std::cout << in << " " << last << "\n";
        else std::cout << last << " " << in << "\n";
    }
};

int m, n, k;
int a[20];

int main() {
    generator();
}