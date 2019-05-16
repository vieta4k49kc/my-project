#include "Animation.h"
using namespace sf;

Animation::Animation(RenderWindow *window, Texture &t, int column, int line, int width, int height, float speed, int count,Vector2f position)
{
	this->m_window = window;
    this->m_speed = speed;
    this->m_Frame = 0;

    for (int i = 0; i < count; i++)
        this->m_Frames.push_back(IntRect(column + width*i, line, width, height));//thêm cấc khung hinh vào Frames
    this->m_sprite.setTexture(t);
    this->m_sprite.setOrigin(width / 2, height / 2);//lay diem trung tam
    this->m_sprite.setPosition(position.x, position.y);
    this->m_sprite.setTextureRect(this->m_Frames[0]);
}

void Animation::update()
{
	this->m_Frame += this->m_speed;
    int n = this->m_Frames.size();// so luong khung hinh
    if (this->m_Frame > n)
        this->m_Frame -= n;
    this->m_sprite.setTextureRect(this->m_Frames[int(this->m_Frame)]);
}

void Animation::draw()
{
	this->m_window->draw(this->m_sprite);
}

bool Animation::checkEnd()
{
    return this->m_Frame + this->m_speed >= this->m_Frames.size();
}

void Animation::setPosition(Vector2f position)
{
    this->m_sprite.setPosition(position.x, position.y);
}
