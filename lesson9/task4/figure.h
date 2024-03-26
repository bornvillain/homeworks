#pragma once

#include <string>

class Figure {
public:
    virtual void GetInfo();

    int GetSides();

    virtual bool IsRegular();

protected:
    int sides = 0;
    std::string name = "Figure";
};