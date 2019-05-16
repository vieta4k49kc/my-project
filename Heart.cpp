#include "Heart.h"
using namespace sf;
using namespace std;
Heart:: Heart(RenderWindow* window,Texture& texture)
{
    this->m_window = window;

    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    this->m_sprite.setRotation(360);// xoay xe 360 là thẳng

    float x = rand() % 500+160;//random vi tri tim
    float y = rand() % 20;
    this->m_sprite.setPosition(x, y);
}

void Heart::update()
{
    this->m_sprite.move(0,3);//0 là hướng đi (càng tăng càng đi chéo)--> auto để 0
                             // 3 là tốc độ của tim
}
void Heart::draw()
{
    this->m_window->draw(this->m_sprite);
}

Vector2f Heart::getPosition()
{
    return this->m_sprite.getPosition();
}
