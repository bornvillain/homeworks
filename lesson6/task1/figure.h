#pragma once

#include <string>

class Figure {
public:

    Figure();

    virtual void GetInfo();

    int GetSides();

    virtual bool IsRegular();

protected:
    Figure(std::string name, int sides);

    int sides = 0;
    std::string name = "Figure";
};

void print_info(Figure *f);