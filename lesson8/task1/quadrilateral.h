#pragma once

#include "figure.h"

class Quadrilateral : public Figure {
public:
    Quadrilateral(int a, int b, int c, int d, double A, double B, double C, double D);

    bool IsRegular() override;

    void GetInfo() override;

private:
    int a, b, c, d;
    double A, B, C, D;
};