#include <iostream>
#include <memory>
#include "./Arena.h"
#include "./Renderer.h"

int main()
{
    auto arena = std::make_shared<Arena>();
    auto renderer = std::make_shared<Renderer>();
    arena->Load("resources/arena.txt");
    renderer->Load(arena);
    while (true)
    {
        renderer->Draw();
        arena->Update();
    }
}