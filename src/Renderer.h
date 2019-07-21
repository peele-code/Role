#pragma once
#include "./Arena.h"

class Renderer
{
public:
    void Load(std::weak_ptr<Arena> arena);
    void Draw() const;
private:
    std::weak_ptr<Arena> _arena;
};