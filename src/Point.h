#pragma once

struct Point
{
    int x;
    int y;
};

enum class PointData : char
{
    EMPTY = ' ',
    WALL = 'X',
    PLAYER = '@'
};