// Xe ô tô mà mình điều khiển

#ifndef _Player_H_
#define _Player_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace sf;

class Player
{
private:
    RenderWindow* m_window;
    Texture m_texture_car;
    Sprite m_sprite_car;

    Texture m_texture_heart;
    Sprite m_sprite_heart;
    int m_countHeart;

public:
    Player(RenderWindow* window);
    void update();
    void draw();
    int& getCountHeart();
    Vector2f getPosition();
};

#endif //  _Player_H_
