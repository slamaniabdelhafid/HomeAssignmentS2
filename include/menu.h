#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Menu
{
    public :
        Text mainmenu[4];
        Text menuText;
        Menu(float width, float height);
        void draw(RenderWindow& Window);
        void Moveup();
        void MoveDown();
        void setSelected(int n);
		bool isExitSelected();
        int pressed(){
            return selected;
        }
		 int getSelected() const { return selected; }
        ~Menu();
    private :
        int selected;
        Font font;
        SoundBuffer moveBuffer;
        Sound moveSound;
		SoundBuffer menuBuffer;
        Sound menuSound;
		

};
#endif
