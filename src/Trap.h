#pragma once
#include <string>
#include <vector>
#include "./Point.h"

class Trap
{
public:
    Trap(const char character, const Point point);
    void Update(const std::vector<std::string> grid);
    const Point GetPosition();
    const char GetSign();
private:
    Point _position;
    char _sign;
    int direction;
};