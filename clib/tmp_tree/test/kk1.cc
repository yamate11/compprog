#include <iostream>

const int n = 50000000;

int op(int n) {
    if(n == 0) return 0;
    return n ^ op(n-1);
}

int main() {
    std::cout << op(n) << '\n';
}
