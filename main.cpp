#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int ekran=1;
bool setPosition=true;
Vector2f positionTankGreen;
float rotationGreen=0;
Vector2f positionTankGray;
float rotationGray=180;

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
    Texture opcjeTexture;
    opcjeTexture.loadFromFile("tloOpcje.jpg");
    Texture tankGreenTexture;
    tankGreenTexture.loadFromFile("tankGreen.png");
    positionTankGreen = Vector2f(860,860);
    window.setFramerateLimit(60);
    positionTankGray = Vector2f(40,40);

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
            Event ev2;
            RectangleShape rectangle;
            rectangle.setFillColor(Color(86, 88, 91));
            Sprite tankGreen(tankGreenTexture);
            Sprite tankGray(tankGreenTexture);
            tankGray.setColor(Color(104, 47, 30));
            tankGreen.setOrigin(Vector2f(20,20));
            tankGray.setOrigin(Vector2f(20,20));
            tankGreen.setPosition(positionTankGreen);
            tankGreen.setRotation(rotationGreen);
            tankGray.setPosition(positionTankGray);
            tankGray.setRotation(rotationGray);
            int akcja=0;
            int liczbaCalkowita=90;
            float predkosc=1;
            int action=0;
            while(window.pollEvent(ev2))
            {
                if(ev2.type == Event::Closed)
                {
                    window.close();
                }
            }

            ///ruch i wykrywanie kolizji dla zielonego czolga

            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                akcja=1;
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                akcja=2;
            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                akcja=3;
            }
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                akcja=4;
            }

            if((tankGreen.getPosition().x+20)>=900)
            {
                akcja=0;
                if(tankGreen.getRotation()<=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        akcja=3;
                    }
                }
                else if(tankGreen.getRotation()>=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        akcja=1;
                    }
                }
            }
            if((tankGreen.getPosition().y+20)>=900)
            {
                akcja=0;
                if(tankGreen.getRotation()<=90 || tankGreen.getRotation()>=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        akcja=1;
                    }
                }
                else if(tankGreen.getRotation()>=90 && tankGreen.getRotation()<=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        akcja=3;
                    }
                }
            }
            if((tankGreen.getPosition().x-20)<=0)
            {
                akcja=0;
                if(tankGreen.getRotation()>=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        akcja=3;
                    }
                }
                else if(tankGreen.getRotation()<=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        akcja=1;
                    }
                }
            }
            if((tankGreen.getPosition().y-20)<=0)
            {
                akcja=0;
                if(tankGreen.getRotation()<=90 || tankGreen.getRotation()>=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        akcja=3;
                    }
                }
                else if(tankGreen.getRotation()>=90 && tankGreen.getRotation()<=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        akcja=1;
                    }
                }
            }

            if(akcja==1)
            {
                if(tankGreen.getRotation()<=90)
                {
                    float stopien = tankGreen.getRotation();
                    float procent = stopien/liczbaCalkowita;
                    float posX = procent;
                    float posY = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x+posX, position.y-posY);
                }
                if(tankGreen.getRotation()>90 && tankGreen.getRotation()<=180)
                {
                    float stopien = tankGreen.getRotation()-90;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x+posX, position.y+posY);
                }
                if(tankGreen.getRotation()>180 && tankGreen.getRotation()<=270)
                {
                    float stopien = tankGreen.getRotation()-180;
                    float procent = stopien/liczbaCalkowita;
                    float posY = predkosc - procent;
                    float posX = procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x-posX, position.y+posY);
                }
                if(tankGreen.getRotation()>270 && tankGreen.getRotation()<=360)
                {
                    float stopien = tankGreen.getRotation()-270;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x-posX, position.y-posY);
                }
                akcja=0;
            }
            if(akcja==2)
            {
                rotationGreen = tankGreen.getRotation()+1;
            }
            if(akcja==3)
            {
                if(tankGreen.getRotation()<=90)
                {
                    float stopien = tankGreen.getRotation();
                    float procent = stopien/liczbaCalkowita;
                    float posX = procent;
                    float posY = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x-posX, position.y+posY);
                }
                if(tankGreen.getRotation()>90 && tankGreen.getRotation()<=180)
                {
                    float stopien = tankGreen.getRotation()-90;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x-posX, position.y-posY);
                }
                if(tankGreen.getRotation()>180 && tankGreen.getRotation()<=270)
                {
                    float stopien = tankGreen.getRotation()-180;
                    float procent = stopien/liczbaCalkowita;
                    float posY = predkosc - procent;
                    float posX = procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x+posX, position.y-posY);
                }
                if(tankGreen.getRotation()>270 && tankGreen.getRotation()<=360)
                {
                    float stopien = tankGreen.getRotation()-270;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGreen.getPosition();
                    positionTankGreen = Vector2f(position.x+posX, position.y+posY);
                }
            }
            if(akcja==4)
            {
                rotationGreen = tankGreen.getRotation()-1;
            }


            ///ruch i wykrywanie kolizji dla szarego czolga

            if(Keyboard::isKeyPressed(Keyboard::W))
            {
                action=1;
            }
            if(Keyboard::isKeyPressed(Keyboard::D))
            {
                action=2;
            }
            if(Keyboard::isKeyPressed(Keyboard::S))
            {
                action=3;
            }
            if(Keyboard::isKeyPressed(Keyboard::A))
            {
                action=4;
            }

            if((tankGray.getPosition().x+20)>=900)
            {
                action=0;
                if(tankGray.getRotation()<=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::S))
                    {
                        action=3;
                    }
                }
                else if(tankGray.getRotation()>=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::W))
                    {
                        action=1;
                    }
                }
            }
            if((tankGray.getPosition().y+20)>=900)
            {
                action=0;
                if(tankGray.getRotation()<=90 || tankGray.getRotation()>=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::W))
                    {
                        action=1;
                    }
                }
                else if(tankGray.getRotation()>=90 && tankGray.getRotation()<=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::S))
                    {
                        action=3;
                    }
                }
            }
            if((tankGray.getPosition().x-20)<=0)
            {
                action=0;
                if(tankGray.getRotation()>=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::S))
                    {
                        action=3;
                    }
                }
                else if(tankGray.getRotation()<=180)
                {
                    if(Keyboard::isKeyPressed(Keyboard::W))
                    {
                        action=1;
                    }
                }
            }
            if((tankGray.getPosition().y-20)<=0)
            {
                action=0;
                if(tankGray.getRotation()<=90 || tankGray.getRotation()>=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::S))
                    {
                        action=3;
                    }
                }
                else if(tankGray.getRotation()>=90 && tankGray.getRotation()<=270)
                {
                    if(Keyboard::isKeyPressed(Keyboard::W))
                    {
                        action=1;
                    }
                }
            }

            if(action==1)
            {
                if(tankGray.getRotation()<=90)
                {
                    float stopien = tankGray.getRotation();
                    float procent = stopien/liczbaCalkowita;
                    float posX = procent;
                    float posY = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x+posX, position.y-posY);
                }
                if(tankGray.getRotation()>90 && tankGray.getRotation()<=180)
                {
                    float stopien = tankGray.getRotation()-90;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x+posX, position.y+posY);
                }
                if(tankGray.getRotation()>180 && tankGray.getRotation()<=270)
                {
                    float stopien = tankGray.getRotation()-180;
                    float procent = stopien/liczbaCalkowita;
                    float posY = predkosc - procent;
                    float posX = procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x-posX, position.y+posY);
                }
                if(tankGray.getRotation()>270 && tankGray.getRotation()<=360)
                {
                    float stopien = tankGray.getRotation()-270;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x-posX, position.y-posY);
                }
                action=0;
            }
            if(action==2)
            {
                rotationGray = tankGray.getRotation()+1;
            }
            if(action==3)
            {
                if(tankGray.getRotation()<=90)
                {
                    float stopien = tankGray.getRotation();
                    float procent = stopien/liczbaCalkowita;
                    float posX = procent;
                    float posY = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x-posX, position.y+posY);
                }
                if(tankGray.getRotation()>90 && tankGray.getRotation()<=180)
                {
                    float stopien = tankGray.getRotation()-90;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x-posX, position.y-posY);
                }
                if(tankGray.getRotation()>180 && tankGray.getRotation()<=270)
                {
                    float stopien = tankGray.getRotation()-180;
                    float procent = stopien/liczbaCalkowita;
                    float posY = predkosc - procent;
                    float posX = procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x+posX, position.y-posY);
                }
                if(tankGray.getRotation()>270 && tankGray.getRotation()<=360)
                {
                    float stopien = tankGray.getRotation()-270;
                    float procent = stopien/liczbaCalkowita;
                    float posY = procent;
                    float posX = predkosc - procent;
                    Vector2f position = tankGray.getPosition();
                    positionTankGray = Vector2f(position.x+posX, position.y+posY);
                }
            }
            if(action==4)
            {
                rotationGray = tankGray.getRotation()-1;
            }

            window.clear(Color(130, 136, 145));
            for(int i=0; i<7; i++)
            {
                if(i==0)
                {
                    rectangle.setSize(Vector2f(20,200));
                    rectangle.setPosition(Vector2f(100,0));
                }
                if(i==1)
                {
                    rectangle.setSize(Vector2f(300,20));
                    rectangle.setPosition(Vector2f(0,700));
                }
                if(i==2)
                {
                    rectangle.setSize(Vector2f(20,500));
                    rectangle.setPosition(Vector2f(450,450));
                }
                if(i==3)
                {
                    rectangle.setSize(Vector2f(200,20));
                    rectangle.setPosition(Vector2f(0,450));
                }
                if(i==4)
                {
                    rectangle.setSize(Vector2f(20,400));
                    rectangle.setPosition(Vector2f(700,0));
                }
                if(i==5)
                {
                    rectangle.setSize(Vector2f(300,20));
                    rectangle.setPosition(300,200);
                }
                if(i==6)
                {
                    rectangle.setSize(Vector2f(200,20));
                    rectangle.setPosition(600,600);
                }
                window.draw(rectangle);
            }
            window.draw(tankGreen);
            window.draw(tankGray);
            window.display();
        }

        while(ekran==2)
        {
            Event ev3;
            Sprite opcje(opcjeTexture);
            Sprite button(buttonTexture);
            bool akcja=false;
            while(window.pollEvent(ev3))
            {
                if(ev3.type == Event::Closed)
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

            window.clear();
            window.draw(opcje);
            text.setString("Powrot");
            text.setCharacterSize(50);
            text.setFillColor(Color::Black);
            text.setPosition(Vector2f(400,800));
            text.setStyle(Text::Bold);
            button.setPosition(Vector2f(250,790));
            if(akcja)
            {
                text.setFillColor(Color::Red);
                akcja=false;
            }
            window.draw(button);
            window.draw(text);
            window.display();


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
                    text.setString("Kierownik ds. Informatyki: Marek Ciezobka.");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,100));
                }
                if(i==2)
                {
                    text.setString("Programista C++: Krzysztof Chowaniec");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,150));
                }
                if(i==3)
                {
                    text.setString("Programista gier komputerowych: Krzysztof Chowaniec");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,200));
                }
                if(i==4)
                {
                    text.setString("Informatyk: Krzysztof Chowaniec, Rafal Banas");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,250));
                }
                if(i==5)
                {
                    text.setString("Kierownik projektu: Miroslaw Zelent");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,300));
                }
                if(i==6)
                {
                    text.setString("Kierownik zespolu: Krzysztof Chowaniec");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,350));
                }
                if(i==7)
                {
                    text.setString("Specjalista do spraw aplikacji: Bartek Krupa");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,400));
                }
                if(i==8)
                {
                    text.setString("Specjalista do spraw IT: Szymon Kolasa");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Black);
                    text.setPosition(Vector2f(20,450));
                }
                if(i==9)
                {
                    text.setString("Stworzone z mysla o: M.Ciezobka, R.Banas, B.Krupa");
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
