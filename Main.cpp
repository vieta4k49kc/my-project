#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Game.h"
#include<SFML/Audio.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(840, 650), "Car Racing", Style::Default);
    window.setFramerateLimit(50);//Giới hạn tốc độ khung hình

    srand(time(NULL));
    //Nhạc nền
    Music music;
    music.openFromFile("D:\\HOC SFML\\gunny.wav");
    music.setLoop(true);
    music.play();
    music.setVolume(30);

    Game game(&window);
    //Loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        game.draw();
        if (!game.update())
        {
           break;
        }
        window.display();
    }
}
