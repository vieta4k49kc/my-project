#include "Threat.h"
using namespace sf;
using namespace std;

Threat:: Threat(RenderWindow* window,Texture& texture)
{
    this->m_window = window;

    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    this->m_sprite.setRotation(180);// xoay xe 180 là thẳng

    float x = rand() % 500+160;//random vi tri vật cản
    float y = rand() % 20;
    this->m_sprite.setPosition(x, y);
}

void Threat::update()
{
    this->m_sprite.move(0,11);//0 là hướng đi (càng tăng càng đi chéo)--> auto để 0
                             // 10 là tốc độ xe cản đường chay
}

void Threat::draw()
{
    this->m_window->draw(this->m_sprite);
}

Vector2f Threat::getPosition()
{
    return this->m_sprite.getPosition();
}
