// VẬT CẢN

#ifndef _Threat_H_
#define _Threat_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace sf;

class Threat
{
private:
    RenderWindow* m_window;
    Sprite m_sprite;

public:
    Threat(RenderWindow* window, Texture& texture);
    void update();
    void draw();
    Vector2f getPosition();
};

#endif //  _Threat_H_
