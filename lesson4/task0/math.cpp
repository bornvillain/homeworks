#include "math.h"

int plus(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int power(int a, int b) {
    int result = a;
    for (int i = 0; i < b - 1; ++i) {
        result = multiply(result, a);
    }
    return result;
}
