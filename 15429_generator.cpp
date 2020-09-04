// test data generator for problem 15429

#include <cstdio>
#include <fstream>

void generator() {
    std::fstream out;
    out.open("./test.in");
    unsigned in;
    srand(time(NULL));
    out << "1000000 1000000 800\n";
    for (int i = 0; i < 1000000; ++i) {
        in = rand()%1000000000 + 1;
        out << in << " ";
    }
    out << "\n";
    int last;
    for (int i = 0; i < 1000000; ++i) {
        last = rand()%1000000 + 1;
        in = rand()%1000000 + 1;
        if (last > in) out << in << " " << last << "\n";
        else out << last << " " << in << "\n";
    }
};

int m, n, k;
int a[20];

int main() {
    generator();
}