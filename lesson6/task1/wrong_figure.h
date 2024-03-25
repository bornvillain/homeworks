#pragma once

#include <stdexcept>

class WrongFigure : public std::domain_error {
public:
    WrongFigure(const std::string &reason);
};