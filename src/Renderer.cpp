#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include "./Renderer.h"

void Renderer::Load(std::weak_ptr<Arena> arena)
{
    this->_arena = arena;
}

void Renderer::Draw() const
{
    if (auto arena = this->_arena.lock())
    {
        system("cls");
        const std::vector<std::string> grid = arena->Grid();
        std::copy(std::begin(grid), std::end(grid), std::ostream_iterator<std::string>(std::cout, "\n"));
    }
}