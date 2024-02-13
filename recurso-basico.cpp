#include <iostream>
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Números primos entre 10 y 30:" << std::endl;
    for (int i = 10; i <= 30; ++i) {
        if (esPrimo(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}