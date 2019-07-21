#pragma once
#include <string>
#include <vector>
#include "./Point.h"
#include "./Trap.h"

class Arena
{
public:
    void Load(const std::string& filePath);
    void Update();
    const std::vector<std::string> Grid();
private:
    std::vector<std::string> _grid;
    std::vector<std::string> _originalArena;
    std::vector<std::unique_ptr<Trap>> _traps;
    Point _playerPosition;
private:
    void FillData(std::ifstream& stream);
private:
    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
};