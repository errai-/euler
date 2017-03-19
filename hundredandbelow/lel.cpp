#include <iostream>

int main(void) {
    int repetitions = 0;
    for (int a =   0; a <  7; ++a) {
    for (int b = a+1; b <  8; ++b) {
    for (int c = b+1; c <  9; ++c) {
    for (int d = c+1; d < 10; ++d) {
        repetitions++;
    }
    }
    }
    }
    std::cout << repetitions << std::endl;
}
