#ifndef POLICE_H
#define POLICE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace sf;

class Police
{
private:
    RenderWindow* m_window;
    Texture m_texture_police;
    Sprite m_sprite_police;

public:
    Police(RenderWindow* window);
    void update();
    void draw();
    Vector2f getPosition();
};
#endif // POLICE_H
