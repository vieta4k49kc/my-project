#include "Player.h"
using namespace sf;

Player::Player(RenderWindow* window) : m_countHeart(2)//số mạng
{
    this->m_window = window;

    this->m_texture_car.loadFromFile("Racer.png");
    this->m_texture_car.setSmooth(true);
    this->m_sprite_car.setTexture(this->m_texture_car);
    this->m_sprite_car.setOrigin(this->m_texture_car.getSize().x / 2, this->m_texture_car.getSize().y / 2);// Xác định điểm trung tâm
    this->m_sprite_car.setPosition(420, 420);//vị trí bắt đầu của xe mình điều khiển

    this->m_texture_heart.loadFromFile("Heart.png");
    this->m_texture_heart.setSmooth(true);
    this->m_sprite_heart.setTexture(this->m_texture_heart);

}

void Player::update()
{
    Vector2f car_position = this->m_sprite_car.getPosition();
    if(car_position.x>180&& car_position.x<680&& car_position.y<580&&car_position.y>80)// xe nằm trong khoảng đường
   {

    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        car_position.x -= 4;// 4 là tốc độ di chuyển tịnh tiến theo phím của xe
    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        car_position.x += 4;
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		car_position.y -= 4;
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		car_position.y += 4;
   }
   else if(car_position.x==180&& car_position.y<580&&car_position.y>80)// xe ở mép đường trái
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) car_position.x += 4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) car_position.y -= 4;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Down)) car_position.y +=4;
   }
   else if(car_position.x==680&& car_position.y<580&&car_position.y>80)//xe ở mép đường phải
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))  car_position.x -= 4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) car_position.y -= 4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) car_position.y += 4;
   }
   else if(car_position.x>180&& car_position.x<680&& car_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))
          car_position.x -= 4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Right))
          car_position.x += 4;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		  car_position.y -= 4;
   }
   else if(car_position.x>180&& car_position.x<680&& car_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))
          car_position.x -= 4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Right))
          car_position.x += 4;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		  car_position.y += 4;
   }
   else if(car_position.x==180&& car_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) car_position.x +=4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) car_position.y -=4;
   }
   else if(car_position.x==180&& car_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) car_position.x +=4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) car_position.y +=4;
   }
   else if(car_position.x==680&& car_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left)) car_position.x -=4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) car_position.y -=4;
   }
   else if(car_position.x==680&& car_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left)) car_position.x -=4;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) car_position.y +=4;
   }

   this->m_sprite_car.setPosition(car_position.x, car_position.y);// vi tri xe sau khi điều khiển theo x,y
}

void Player::draw()
{
    for (int i = 0; i < this->m_countHeart; i++)
    {

        this->m_sprite_heart.setPosition(10+i*30, 10);// 30 là khoảng cách giữa các tim, 10 là khoáng cách mép trên theo chiều dọc
                                                    // 10 là khoảng cách giữa tim đầu tiên với lề theo chiều ngang
        this->m_window->draw(this->m_sprite_heart);
    }

    this->m_window->draw(this->m_sprite_car);
}

int& Player::getCountHeart()
{
    return this->m_countHeart;
}

Vector2f Player::getPosition()
{
    return this->m_sprite_car.getPosition();
}
