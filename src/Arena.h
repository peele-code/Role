#pragma once
#include <string>
#include <vector>

#include "./Point.h"

class Arena
{
public:
    void Load(const std::string& filePath);
    void Update();
    const std::vector<std::string> Grid();
private:
    std::vector<std::string> _grid;
    std::vector<std::string> _originalArena;
    Point _playerPosition;

    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
};