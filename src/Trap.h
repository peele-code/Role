#pragma once
#include <string>
#include <vector>
#include "./Point.h"

class Trap
{
public:
    Trap(const char character, const Point point);
    void Update(const std::vector<std::string>& grid);
    Point GetPosition() const;
    char GetSign() const;
private:
    Point _position = Point();
    char _sign;
    int direction;
};