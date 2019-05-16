#include "Police.h"
using namespace sf;

Police::Police(RenderWindow* window)
{
    this->m_window = window;

    this->m_texture_police.loadFromFile("Police.png");
    this->m_texture_police.setSmooth(true);
    this->m_sprite_police.setTexture(this->m_texture_police);
    this->m_sprite_police.setOrigin(this->m_texture_police.getSize().x / 2, this->m_texture_police.getSize().y / 2);// Xác định điểm trung tâm
    this->m_sprite_police.setPosition(420, 550);
}

void Police::update()
{
    Vector2f police_position = this->m_sprite_police.getPosition();
    if(police_position.x>180&& police_position.x<680&& police_position.y<580&&police_position.y>80)// xe nằm trong khoảng đường
   {

    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        police_position.x -= 3;
    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        police_position.x += 3;
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		police_position.y -= 3;
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		police_position.y += 3;
   }
   else if(police_position.x==180&& police_position.y<580&&police_position.y>80)// xe ở mép đường trái
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) police_position.x += 3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) police_position.y -= 3;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Down)) police_position.y +=3;
   }
   else if(police_position.x==680&& police_position.y<580&&police_position.y>80)//xe ở mép đường phải
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))  police_position.x -= 3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) police_position.y -= 3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) police_position.y += 3;
   }
   else if(police_position.x>180&& police_position.x<680&& police_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))
          police_position.x -= 3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Right))
          police_position.x += 3;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		  police_position.y -= 3;
   }
   else if(police_position.x>180&& police_position.x<680&& police_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left))
          police_position.x -= 3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Right))
          police_position.x += 3;
	   if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		  police_position.y += 3;
   }
   else if(police_position.x==180&& police_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) police_position.x +=3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) police_position.y -=3;
   }
   else if(police_position.x==180&& police_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Right)) police_position.x +=3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) police_position.y +=3;
   }
   else if(police_position.x==680&& police_position.y==580)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left)) police_position.x -=3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Up)) police_position.y -=3;
   }
   else if(police_position.x==680&& police_position.y==80)
   {
       if (Keyboard::isKeyPressed(Keyboard::Key::Left)) police_position.x -=3;
       if (Keyboard::isKeyPressed(Keyboard::Key::Down)) police_position.y +=3;
   }

   this->m_sprite_police.setPosition(police_position.x, police_position.y);
}

void Police::draw()
{
    this->m_window->draw(this->m_sprite_police);
}

Vector2f Police::getPosition()
{
    return this->m_sprite_police.getPosition();
}


