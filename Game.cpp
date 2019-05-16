#include "Game.h"
using namespace sf;
using namespace std;

double BackgroundY1=0;
double BackgroundY2=-650;

Game::Game(RenderWindow* window) : m_score(0)//0 là số điểm lúc xuất phát
{
    this->m_window = window;

    this->m_player = new Player(this->m_window);//cấp bộ nhớ động
    this->m_police = new Police(this->m_window);

    this->m_texture_threat_1.loadFromFile("Car_1.png");
    this->m_texture_threat_2.loadFromFile("Car_2.png");
    this->m_texture_threat_3.loadFromFile("Car_3.png");
    this->m_texture_threat_4.loadFromFile("Bomb.png");

    this->m_texture_police.loadFromFile("Car_1.png");

    this->m_texture_explosion.loadFromFile("Explosion.png");

    this->m_texture_road.loadFromFile("background.png");
    this->m_sprite_road.setTexture(this->m_texture_road);
    this->m_sprite_road2.setTexture(this->m_texture_road);

    this->m_font.loadFromFile("MarkerFelt.ttf");
    this->m_text.setFont(this->m_font);
    this->m_text.setString("Score: ");
    this->m_text.setStyle(Text::Underlined | Text::Italic);//kiểu chữ
    this->m_text.setFillColor(Color(255,255,255,255));//màu chữ
    this->m_text.setCharacterSize(25);// 25 là cỡ chữ score
    this->m_text.setPosition(720, 5);//710 là vi tri chữ score theo chiều ngang
                                      //5  là vi tri chữ score theo chiều dọc
}

Game::~Game()
{
    delete this->m_player;//xóa bộ nhớ động
}

bool Game::update()
{
    // Tạo cảm giác cảnh vật di chuyển ngược lại
    m_sprite_road.setPosition(0,BackgroundY1);
    m_sprite_road2.setPosition(0,BackgroundY2);
    if (BackgroundY2>0)
    {
        BackgroundY1=0;
        BackgroundY2=BackgroundY1-650;// road chạy hết 600 pixel thi chuyen road2
        this->count++;
    }
    //Level
    if(this->count<=1)
    {
       BackgroundY1+=3;//tốc độ chuyển 2 khung ảnh đường
       BackgroundY2+=3;
    }
    if(this->count==2)
    {
       BackgroundY1+=5;
       BackgroundY2+=5;
    }
    if(this->count>=3)
    {
       BackgroundY1+=7;
       BackgroundY2+=7;
    }

    this->m_player->update();
    this->m_police->update();

    if (this->m_explosion.size() > 0)
    {
        for (list<Animation>::iterator it = this->m_explosion.begin(); it != this->m_explosion.end(); it++)
        {
            it->update();
        }
        if (this->m_explosion.begin()->checkEnd())
        {
           this->m_explosion.pop_front();
        }
    }

    if (this->m_threat.size() > 0)
    {
          for (list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
          {
              it->update();
          }

          for (list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
          {
              // khoảng cách giữa xe-vật để tính là đâm nhau
              int x = abs(this->m_player->getPosition().x - it->getPosition().x);
              int y = abs(this->m_player->getPosition().y - it->getPosition().y);

              int X = abs(this->m_police->getPosition().x - it->getPosition().x);
              int Y = abs(this->m_police->getPosition().y - it->getPosition().y);

              int X1 = abs(this->m_police->getPosition().x - this->m_player->getPosition().x);
              int Y1 = abs(this->m_police->getPosition().y - this->m_player->getPosition().y);

              int check_x = (this->m_player->getPosition().x < it->getPosition().x) ? this->m_player->getPosition().x : it->getPosition().x;
              int check_y = (this->m_player->getPosition().y < it->getPosition().y) ? this->m_player->getPosition().y : it->getPosition().y;

              int check_X = (this->m_police->getPosition().x < it->getPosition().x) ? this->m_police->getPosition().x : it->getPosition().x;
              int check_Y = (this->m_police->getPosition().y < it->getPosition().y) ? this->m_police->getPosition().y : it->getPosition().y;

              if (x <= 70&& y<=95)//đâm nhau
              {
                  this->m_threat.erase(it);
				  this->m_player->getCountHeart()--;
				  this->m_explosion.push_back(Animation(this->m_window, this->m_texture_explosion, 0, 0, 50, 50, 1, 20,Vector2f(check_x + x/3, check_y + y/3)));
				  break;
              }


              if (X <= 70&& Y<=95)
              {
                  this->m_threat.erase(it);
				  this->m_explosion.push_back(Animation(this->m_window, this->m_texture_explosion, 0, 0, 50, 50, 1, 20,Vector2f(check_X + X/3, check_Y + Y/3)));
				  break;
              }

              if (X1 <= 70&& Y1<=110)
              {
                  this->m_player->getCountHeart()-=this->m_player->getCountHeart();
				  this->m_explosion.push_back(Animation(this->m_window, this->m_texture_explosion, 0, 0, 50, 50, 1, 20,Vector2f(check_x + x / 2, check_y + y / 2)));
				  break;
              }
          }

          if (this->m_threat.size() > 0 && this->m_threat.begin()->getPosition().y >= 650)
          {
              this->m_threat.pop_front();
			  this->m_score += 10;
          }
    }

    cout << "Score: " << this->m_score <<endl;

    this->m_time = this->m_clock.getElapsedTime();
    if (this->m_time.asSeconds() > 0.35)// thời gian random các xe trong 1 lần rồi restart lai
    {
        switch (rand() % 4)
        {
        case 0:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_1));
            break;
        case 1:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_2));
            break;
        case 2:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_3));
            break;
        case 3:
            this->m_threat.push_back(Threat(this->m_window, this->m_texture_threat_4));
            break;

        }
        this->m_clock.restart();
    }

    this->m_text.setString("Score: " + to_string(this->m_score));

    if (this->m_player->getCountHeart() ==0)
    {
       cout<<"You are Loser";
       return false;
    }
    return true ;
}

void Game::draw()
{
    this->m_window->draw(this->m_sprite_road);
    this->m_window->draw(this->m_sprite_road2);
    if(this->m_threat.size()>0)
    {
       for (list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
       {
         it->draw();
       }
    }

    if (this->m_explosion.size() > 0)
    {
        for (list<Animation>::iterator it = this->m_explosion.begin(); it != this->m_explosion.end(); it++)
        {
             it->draw();
        }
    }
   this->m_player->draw();
   this->m_window->draw(this->m_text);
   this->m_police->draw();
}

