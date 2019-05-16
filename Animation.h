//Tạo hiệu ứng nổ

#ifndef _Animation_H_
#define _Animation_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;
using namespace sf;

class Animation
{
private:
    RenderWindow *m_window;
    Sprite m_sprite;
    float m_speed;
    float m_Frame;
    vector <IntRect> m_Frames;//luu cac khung hinh thanh 1 loat cac anh lien tiep
public:
    Animation(RenderWindow * window, Texture &t, int column, int line, int width, int height, float speed, int count, sf::Vector2f position);
    void update();
    void draw();
    bool checkEnd();
    void setPosition(Vector2f position);
};

#endif //   _Animation_H_
