#include <SFML/Graphics.hpp>

using namespace sf;

int ekran=0;

int main()
{
    RenderWindow window(VideoMode(900,900),"Tank Wars III",Style::Close);
    Texture menuTexture;
    menuTexture.loadFromFile("tloMenu.jpg");
    Font font;
    font.loadFromFile("arial.ttf");
    Text text;
    text.setFont(font);
    Texture buttonTexture;
    buttonTexture.loadFromFile("button.png");
    Texture tworcyTexture;
    tworcyTexture.loadFromFile("tloTworcy.jpg");

    while(window.isOpen())
    {
        while(ekran==0)
        {
            int akcja=0;
            Sprite menu(menuTexture);
            Sprite button(buttonTexture);
            Event ev1;
            while(window.pollEvent(ev1))
            {
                if(ev1.type == Event::Closed)
                {
                    window.close();
                }
            }

            if(Mouse::getPosition(window).x>300 && Mouse::getPosition(window).x< 500 && Mouse::getPosition(window).y>300 && Mouse::getPosition(window).y<350)
            {
                akcja=1;
            }
            if(Mouse::getPosition(window).x>300 && Mouse::getPosition(window).x< 500 && Mouse::getPosition(window).y>400 && Mouse::getPosition(window).y<450)
            {
                akcja=2;
            }
            if(Mouse::getPosition(window).x>300 && Mouse::getPosition(window).x< 500 && Mouse::getPosition(window).y>500 && Mouse::getPosition(window).y<550)
            {
                akcja=3;
            }
            if(Mouse::getPosition(window).x>300 && Mouse::getPosition(window).x< 500 && Mouse::getPosition(window).y>600 && Mouse::getPosition(window).y<650)
            {
                akcja=4;
            }

            if(akcja==1 && Mouse::isButtonPressed(Mouse::Left))
            {
                ekran=1;
            }
            if(akcja==2 && Mouse::isButtonPressed(Mouse::Left))
            {
                ekran=2;
            }
            if(akcja==3 && Mouse::isButtonPressed(Mouse::Left))
            {
                ekran=3;
            }
            if(akcja==4 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
            }

            window.clear(Color(11, 96, 21));
            window.draw(menu);

            for(int i=0; i<6; i++)
            {
               if(i==0)
               {
                   text.setString("!Tank Wars III!");
                   text.setCharacterSize(100);
                   text.setFillColor(Color(155, 77, 17));
                   text.setStyle(Text::Bold | Text::Underlined);
                   text.setPosition(Vector2f(100,50));
               }
               if(i==1)
               {
                   text.setString("Graj!");
                   text.setCharacterSize(50);
                   text.setFillColor(Color::Blue);
                   text.setStyle(Text::Bold);
                   text.setPosition(Vector2f(350,300));
                   button.setPosition(Vector2f(200,290));
                   window.draw(button);

                   if(akcja==1)
                   {
                       text.setFillColor(Color::Red);
                       text.setStyle(Text::Bold | Text::Underlined);
                       akcja=0;
                   }
               }
               if(i==2)
               {
                   text.setString("Opcje");
                   text.setCharacterSize(50);
                   text.setFillColor(Color::Blue);
                   text.setStyle(Text::Bold);
                   text.setPosition(Vector2f(350,400));
                   button.setPosition(Vector2f(200,390));
                   window.draw(button);

                   if(akcja==2)
                   {
                       text.setFillColor(Color::Red);
                       text.setStyle(Text::Bold | Text::Underlined);
                       akcja=0;
                   }
               }
               if(i==3)
               {
                   text.setString("Wyjdz");
                   text.setCharacterSize(50);
                   text.setFillColor(Color::Blue);
                   text.setStyle(Text::Bold);
                   text.setPosition(Vector2f(350,600));
                   button.setPosition(Vector2f(200,590));
                   window.draw(button);

                   if(akcja==4)
                   {
                       text.setFillColor(Color::Red);
                       text.setStyle(Text::Bold | Text::Underlined);
                       akcja=0;
                   }
               }
               if(i==4)
               {
                   text.setString("Tworcy");
                   text.setCharacterSize(50);
                   text.setFillColor(Color::Blue);
                   text.setStyle(Text::Bold);
                   text.setPosition(Vector2f(350,500));
                   button.setPosition(Vector2f(200,490));
                   window.draw(button);

                   if(akcja==3)
                   {
                       text.setFillColor(Color::Red);
                       text.setStyle(Text::Bold | Text::Underlined);
                       akcja=0;
                   }
               }
               if(i==5)
               {
                   text.setString("Gra stworzona przez zespol \"KRap Industries\". Zakaz kopiowania danych gry. Milej zabawy!");
                   text.setCharacterSize(10);
                   text.setFillColor(Color::Black);
                   text.setPosition(Vector2f(150,870));
               }
               window.draw(text);
            }

            window.display();
        }

        while(ekran==1)
        {
        }

        while(ekran==2)
        {
        }

        while(ekran==3)
        {
            Event ev4;
            Sprite tworcy(tworcyTexture);
            Sprite button(buttonTexture);
            bool akcja=false;
            while(window.pollEvent(ev4))
            {
                if(ev4.type == Event::Closed)
                {
                    window.close();
                }
            }

            if(Mouse::getPosition(window).x>400 && Mouse::getPosition(window).x<600 && Mouse::getPosition(window).y>800 && Mouse::getPosition(window).y<850)
            {
                akcja=true;
            }
            if(akcja==true && Mouse::isButtonPressed(Mouse::Left))
            {
                ekran=0;
            }

            window.clear(Color::Black);
            window.draw(tworcy);
            for(int i=0; i<11; i++)
            {
                if(i==0)
                {
                    text.setString("Gra stworzona przez zespol \" KRap Industries\".");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,50));
                }
                if(i==1)
                {
                    text.setString("Kierownik ds. Informatyki: XXX.");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,100));
                }
                if(i==2)
                {
                    text.setString("Programista C++: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,150));
                }
                if(i==3)
                {
                    text.setString("Programista gier komputerowych: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,200));
                }
                if(i==4)
                {
                    text.setString("Informatyk: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,250));
                }
                if(i==5)
                {
                    text.setString("Kierownik projektu: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,300));
                }
                if(i==6)
                {
                    text.setString("Kierownik zespolu: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,350));
                }
                if(i==7)
                {
                    text.setString("Specjalista do spraw aplikacji: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,400));
                }
                if(i==8)
                {
                    text.setString("Specjalista do spraw IT: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,450));
                }
                if(i==9)
                {
                    text.setString("Stworzone z mysla o: XXX");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,500));
                }
                if(i==10)
                {
                    text.setString("Powrot");
                    text.setCharacterSize(50);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(400,800));
                    text.setStyle(Text::Bold);
                    button.setPosition(Vector2f(250,790));
                    window.draw(button);

                    if(akcja)
                    {
                        text.setFillColor(Color::Red);
                        akcja=false;
                    }
                }
                window.draw(text);
            }
            window.display();
        }
    }
}
