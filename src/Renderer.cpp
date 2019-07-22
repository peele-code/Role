#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include "./Renderer.h"

void Renderer::Load(const std::weak_ptr<Arena>& arena)
{
    this->_arena = arena;
}

void Renderer::Draw() const
{
    if (const auto arena = this->_arena.lock())
    {
        system("cls");
        auto grid = arena->Grid();
        std::copy(std::begin(grid), std::end(grid), std::ostream_iterator<std::string>(std::cout, "\n"));
    }
}