#pragma once

#include<iostream>
#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c, double A, double B, double C);

    bool IsRegular() override;

    void GetInfo() override;

protected:
    int a, b, c;
    double A, B, C;
};
