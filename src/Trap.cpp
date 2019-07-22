#include "Trap.h"

Trap::Trap(const char character, const Point point)
{
    this->_position = point;
    this->_sign = character;
    this->direction = 1;
}

void Trap::Update(const std::vector<std::string>& grid)
{
    this->_position.x += this->direction;
    const auto data = static_cast<PointData>(grid[this->_position.y][this->_position.x]);
    if (data == PointData::EMPTY)
    {
        return;
    }

    this->direction *= -1;
    this->_position.x += this->direction * 2;
}

Point Trap::GetPosition() const
{
    return this->_position;
}

char Trap::GetSign() const
{
    return this->_sign;
}
