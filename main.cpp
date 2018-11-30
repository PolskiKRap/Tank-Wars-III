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

    while(window.isOpen())
    {
        while(ekran==0)
        {
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
    }
}
