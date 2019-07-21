#include "Trap.h"

Trap::Trap(const char character, const Point point)
{
    this->_position = point;
    this->_sign = character;
    this->direction = 1;
}

void Trap::Update(const std::vector<std::string> grid)
{
    this->_position.x += this->direction;
    PointData data = (PointData)grid[this->_position.y][this->_position.x];
    if (data == PointData::EMPTY)
    {
        return;
    }

    this->direction *= -1;
    this->_position.x += this->direction * 2;
}

const Point Trap::GetPosition()
{
    return this->_position;
}

const char Trap::GetSign()
{
    return this->_sign;
}
