#ifndef HEART_H
#define HEART_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace sf;

class Heart
{
private:
    RenderWindow* m_window;
    Sprite m_sprite;

public:
    Heart(RenderWindow* window, Texture& texture);
    void update();
    void draw();
    Vector2f getPosition();
};

#endif // HEART_H
