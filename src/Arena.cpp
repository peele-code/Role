#include <fstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "./Arena.h"
#include "./Point.h"

bool Move(Point& point);

void Arena::Load(const std::string& filePath)
{
    std::ifstream fileStream(filePath);
    FillData(fileStream);
    this->_originalArena.reserve(this->_grid.size());
    std::copy(this->_grid.begin(), this->_grid.end(), std::back_inserter(this->_originalArena));
    this->_originalArena[this->_playerPosition.y][this->_playerPosition.x] = static_cast<char>(PointData::EMPTY);
    for (auto const& it : this->_traps)
    {
        const Point point = it->GetPosition();
        this->_originalArena[point.y][point.x] = static_cast<char>(PointData::EMPTY);
    }
}

void Arena::FillData(std::ifstream& stream)
{
    int rowNumber = 0;
    for (std::string line; std::getline(stream, line);)
    {
        int colNumber = 0;
        std::string row;
        std::copy_if(std::begin(line), std::end(line), std::back_inserter(row), [&](decltype(row)::value_type character)
        {
            switch (static_cast<PointData>(character))
            {
                case PointData::PLAYER:
                {
                    this->_playerPosition.x = colNumber;
                    this->_playerPosition.y = rowNumber;
                    break;
                }

                case PointData::TRAP:
                {
                    auto point = Point();
                    point.x = colNumber;
                    point.y = rowNumber;
                    this->_traps.emplace_back(new Trap(character, point));
                    break;
                }

                default:
                {
                    break;
                }
            }

            ++colNumber;
            return true;
        });

        this->_grid.push_back(std::move(row));
        ++rowNumber;
    }
}

void Arena::Update()
{
    Point nextPosition = this->_playerPosition;
    if (!Move(nextPosition))
    {
        return;
    }

    if (nextPosition.y < 0 || nextPosition.y >= static_cast<int>(this->_grid.size()))
    {
        return;
    }

    if (nextPosition.x < 0 || nextPosition.x >= static_cast<int>(this->_grid[nextPosition.y].size()))
    {
        return;
    }

    const auto data = static_cast<PointData>(this->_grid[nextPosition.y][nextPosition.x]);
    if (data != PointData::EMPTY)
    {
        return;
    }

    this->_grid[nextPosition.y][nextPosition.x] = (char)PointData::PLAYER;
    this->_grid[this->_playerPosition.y][this->_playerPosition.x] = this->_originalArena[this->_playerPosition.y][this->_playerPosition.x];
    this->_playerPosition.x = nextPosition.x;
    this->_playerPosition.y = nextPosition.y;
	for (auto const& trap : this->_traps)
    {
        Point point = trap->GetPosition();
        this->_grid[point.y][point.x] = this->_originalArena[point.y][point.x];
        trap->Update(this->_grid);
        point = trap->GetPosition();
        this->_grid[point.y][point.x] = static_cast<char>(trap->GetSign());
    }
}

std::vector<std::string> Arena::Grid() const
{
    return this->_grid;
}

bool Move(Point& point)
{
    char key;
    std::cin >> key;
    switch (key)
    {
        case 'w':
        {
            --point.y;
            break;
        }

        case 's':
        {
            ++point.y;
            break;
        }

        case 'a':
        {
            --point.x;
            break;
        }

        case 'd':
        {
            ++point.x;
            break;
        }

        default:
        {
            return false;
            break;
        }
    }

    return true;
}
