// test data generator for problem 15429

#include <cstdio>
#include <fstream>
#include <iostream>

void generator() {
    unsigned in;
    srand(time(NULL));
    std::cout << "10 10 30\n";
    for (int i = 0; i < 10; ++i) {
        in = rand()%10 + 1;
        std::cout << in << " ";
    }
    std::cout << "\n";
    int last;
    for (int i = 0; i < 10; ++i) {
        last = rand()%10 + 1;
        in = rand()%10 + 1;
        if (last > in) std::cout << in << " " << last << "\n";
        else std::cout << last << " " << in << "\n";
    }
};

int m, n, k;
int a[20];

int main() {
    generator();
}