#ifndef _Game_H_
#define _Game_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Threat.h"
#include "Animation.h"
#include <list>
#include "Police.h"

using namespace sf;
using namespace std;

class Game
{
private:
    RenderWindow* m_window;

    Texture m_texture_threat_1;
    Texture m_texture_threat_2;
    Texture m_texture_threat_3;
    Texture m_texture_threat_4;

    Texture m_texture_police;

    Texture m_texture_road;
    Texture m_texture_heart;
    Texture m_texture_explosion;

    Sprite sprite;
    Sprite m_sprite_road;
    Sprite m_sprite_road2;

    Player* m_player;
    Police* m_police;

    Clock m_clock;
    Time m_time;

    list<Threat> m_threat;
    list<Animation> m_explosion;

    int m_score;
    double count=0;
    Font m_font;
    Text m_text;

public:
    Game(RenderWindow* window);
    ~Game();
    bool update();
    void draw();
};

#endif //   _Game_H_
