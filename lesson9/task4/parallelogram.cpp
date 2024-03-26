#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) {
    name = "Parallelogram";
}
