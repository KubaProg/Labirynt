
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Square.h"
#include "Reward.h"
#include "Obstacle.h"
#include "Point.h"

using namespace std;
using namespace sf;

//SFML czyli Simple and Fast Multimedia Library to open sourcowa biblioteka obslugujaca multimedia, sfml jest zorientowana
//obiektowo, ma dobra dokumentacje , stworzona jest glownie z mysl¹ o grach 2d, mamyy w niej takie Klasy jak Window, Sprite, Shape, Text, Event i
//inne umo¿liwiaj¹ce wygodne tworzenie tego typu rozwi¹zañ jak ten projekt. Do reprezntacji punktu oraz wektora w przestrzeni mamy wektory.


bool isIntersecting(Reward reward, Square square) // sprawdzenie czy pilka dotyka paletki
{
    return reward.right() >= square.left() && reward.left() <= square.right()
        && reward.bottom() >= square.top() && reward.top() <= square.bottom();
}

bool isIntersecting(Obstacle obstacle, Square square) // sprawdzenie czy pilka dotyka paletki
{
    return obstacle.right() >= square.left() && obstacle.left() <= square.right()
        && obstacle.bottom() >= square.top() && obstacle.top() <= square.bottom();
}

bool isIntersecting(Point point, Square square) // sprawdzenie czy pilka dotyka paletki
{
    return point.right() >= square.left() && point.left() <= square.right()
        && point.bottom() >= square.top() && point.top() <= square.bottom();
}


int main()
{
    Square square(50, 100); // kwadrat do poruszania nim
    Reward reward(725, 200); // nagroda (kulka na koncu labiryntu)
    Reward monster(50, 400, Color::Red);
    Reward monster3(440, 400, Color::Red);
    Reward monster4(550, 400, Color::Red);
    Point point(50, 300);
    Point point2(50, 450);
    Point point3(700, 400);
    Obstacle obstacle1(200, 25, 800, 50); // przeszkody kolejne:
    Obstacle obstacle2(250, 75, 50, 900);
    Obstacle obstacle3(600, 100, 400, 50);
    Obstacle obstacle4(500, 350, 50, 300);
    Obstacle obstacle5(50, 170, 200, 50);
    Obstacle obstacle6(250, 300, 320, 50);
    Obstacle obstacle7(120, 550, 50, 300);
    Obstacle obstacle8(380, 550, 50, 300);
    Obstacle obstacle9(620, 300, 50, 450);

    RenderWindow window(VideoMode(800, 600), "Labirynt"); //kostruktor klasy RenderWindow , inicjalizuje wielkosc okna i nadaje nazwe
    window.setFramerateLimit(60); // Wymuszamy aby gameloop dzia³a³ 60x/s 
    Font font;
    font.loadFromFile("Fonts/OpenSans-ExtraBold.ttf");

    Text title; 
    Text enter;
    Text exit1;
    Text win, win2, win3, win4;
    Text lost, lost1, lost2;
    Text again;

    Texture t;
    t.loadFromFile("background.jpg");
    Sprite s(t); // klasa Sprite do wyswietlania obrazkow tutaj akurat objet s przyjmuje argument t z klasy texture

    Texture t2;
    t2.loadFromFile("menu.jpg");
    Sprite bgc(t2); // klasa Sprite do wyswietlania obrazkow tutaj akurat objet s przyjmuje argument t z klasy texture

    int points = 0;

    again.setFont(font);
    again.setCharacterSize(80);
    again.setFillColor(Color::Blue);
    again.setStyle(Text::Bold);
    again.setPosition(15, 400);
    again.setString("'Enter'-> Od nowa");

    title.setFont(font);
    title.setCharacterSize(80);
    title.setFillColor(Color::Blue);
    title.setStyle(Text::Bold);
    title.setPosition(200, 50);
    title.setString("Labirynt");

    enter.setFont(font);
    enter.setCharacterSize(45);
    enter.setFillColor(Color::Red);
    enter.setStyle(Text::Bold);
    enter.setPosition(210, 400);
    enter.setString("START -> 'enter'");

    exit1.setFont(font);
    exit1.setCharacterSize(45);
    exit1.setFillColor(Color::Red);
    exit1.setStyle(Text::Bold);
    exit1.setPosition(180, 500);
    exit1.setString("Exit -> 'Backspace' ");

    win.setFont(font);
    win.setCharacterSize(80);
    win.setFillColor(Color::Blue);
    win.setStyle(Text::Bold);
    win.setPosition(200, 220);
    win.setString("Wygrales");

    win2.setFont(font);
    win2.setCharacterSize(80);
    win2.setFillColor(Color::Blue);
    win2.setStyle(Text::Bold);
    win2.setPosition(100, 220);
    win2.setString("Wygrales:1pkt");

    win3.setFont(font);
    win3.setCharacterSize(80);
    win3.setFillColor(Color::Blue);
    win3.setStyle(Text::Bold);
    win3.setPosition(100, 220);
    win3.setString("Wygrales:2pkt");

    win4.setFont(font);
    win4.setCharacterSize(80);
    win4.setFillColor(Color::Blue);
    win4.setStyle(Text::Bold);
    win4.setPosition(100, 220);
    win4.setString("Wygrales:3pkt");

    lost.setFont(font);
    lost.setCharacterSize(80);
    lost.setFillColor(Color::Blue);
    lost.setStyle(Text::Bold);
    lost.setPosition(180, 220);
    lost.setString("Przegrales");

    lost1.setFont(font);
    lost1.setCharacterSize(80);
    lost1.setFillColor(Color::Blue);
    lost1.setStyle(Text::Bold);
    lost1.setPosition(90, 220);
    lost1.setString("Przegrales:1pkt");

    lost2.setFont(font);
    lost2.setCharacterSize(80);
    lost2.setFillColor(Color::Blue);
    lost2.setStyle(Text::Bold);
    lost2.setPosition(90, 220);
    lost2.setString("Przegrales:2pkt");

    SoundBuffer buffer2;
    buffer2.loadFromFile("gameover.wav");
    Sound sound2;
    sound2.setBuffer(buffer2);
    sound2.setVolume(10);

    SoundBuffer buffer3;
    buffer3.loadFromFile("start.wav");
    Sound sound3;
    sound3.setBuffer(buffer3);

    SoundBuffer buffer4;
    buffer4.loadFromFile("congratulations.wav");
    Sound sound4;
    sound4.setBuffer(buffer4);
    sound4.setVolume(10);

    while (true) // PÊTLA Z MENU 
    {
        Event event; // Klasa do wy³apywania wszelkich zdarzeñ
        window.pollEvent(event); // wylapywanie zdarzen w obrêbie okna aplikacji, aby warunek ponizej dzialal (zamykanie na 'x)
        // metoda pollEvent zwraca prawde, jesli uda sie pobrac zdarzenia z kontenera, zmienna event dostaje informacje o odczytanym zdarzeniu,
        // w tym przypadku chodzi o zdarzenie "closed"

        if (event.type == Event::Closed) { // Jeœli klikamy 'X' w prawym gornym rogu to:
            window.close();
            break;
        }

        window.clear(Color::Black); // czyscimy ekran i ustawiamy tlo na czarno   

        window.draw(bgc); // rysowanie tapety
        window.draw(title); // napis labirynt
        window.draw(enter); // napis enter
        window.draw(exit1); //napis exit

        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            sound3.play();
            break;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Key::Backspace))
        {
            window.close();
        }

        window.display(); // metoda wyœwietla obiekty, bez niej nic by sie wyswietlilo sie, biale tlo    


    }

    while (true) {

        while (window.isOpen()) // TUTAJ SIE BEDZIE DZIALA CALA GRA DO MOMENTU WYGRANEJ LUB PRZEGRANEJ
        {

            Event event; // Klasa do wy³apywania wszelkich zdarzeñ
            window.pollEvent(event); // wylapywanie zdarzen w obrêbie okna aplikacji, aby warunek ponizej dzialal (zamykanie na 'x)
            // metoda pollEvent zwraca prawde, jesli uda sie pobrac zdarzenia z kontenera, zmienna event dostaje informacje o odczytanym zdarzeniu,
            // w tym przypadku chodzi o zdarzenie "closed"

            if (event.type == Event::Closed) { // Jeœli klikamy 'X' w prawym gornym rogu to:
                window.close();
                break;
            }

            window.clear(Color::Yellow); // czyscimy ekran i ustawiamy tlo na zolto, chociaz i tak jest tapeta wiec nie ma to znaczenia   

            window.draw(s); // tapeta ekranu glownego gry
            window.draw(reward);  // rysowanie nagrody (kulki)
            window.draw(monster);     
            window.draw(monster3);
            window.draw(monster4);
            window.draw(square);  // rysowanie kwadratu
            window.draw(point);
            window.draw(point2);
            window.draw(point3);
            window.draw(obstacle1); // rysowanie przeszkody
            window.draw(obstacle2);
            window.draw(obstacle3); 
            window.draw(obstacle4);
            window.draw(obstacle5);
            window.draw(obstacle6);
            window.draw(obstacle7);
            window.draw(obstacle8);
            window.draw(obstacle9);

            square.update(); // update pozycji kwadratu w zaleznosci od strza³ki
            reward.update(); // update pozycji nagrody, lata w gore i w dol stale
            monster.updateMonster();
            monster3.updateMonster();
            monster4.updateMonster();

            if (isIntersecting(point,square) || isIntersecting(point2, square) || isIntersecting(point3, square)  ) {
              points++;          
              if (isIntersecting(point, square)) {
                  point.getOut();
              }
              else if (isIntersecting(point2, square)) {
                  point2.getOut();
              }
              else if (isIntersecting(point3, square)) {
                  point3.getOut();
              }
            }

            if (isIntersecting(obstacle1, square) || isIntersecting(obstacle2, square) || isIntersecting(obstacle3, square)
                || isIntersecting(obstacle4, square) || isIntersecting(obstacle5, square) || isIntersecting(obstacle6, square)
                || isIntersecting(obstacle7, square) || isIntersecting(obstacle8, square) || isIntersecting(obstacle9, square)
                || isIntersecting(monster,square) || isIntersecting(monster3, square) || isIntersecting(monster4, square)
                )
            {

                sound2.play();

                while (true)  // PETLA MOWIACA ZE SIE PRZEGRALO
                {
                    window.pollEvent(event); // wylapywanie zdarzen w obrêbie okna aplikacji, aby warunek ponizej dzialal (zamykanie na 'x)
                    // metoda pollEvent zwraca prawde, jesli uda sie pobrac zdarzenia z kontenera, zmienna event dostaje informacje o odczytanym zdarzeniu,
                    // w tym przypadku chodzi o zdarzenie "closed"

                    if (event.type == Event::Closed) { // Jeœli klikamy 'X' w prawym gornym rogu to:    
                        window.close();
                        break;
                    }

                    if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
                        square.setPos(); 
                        point.setPos(50, 300);
                        point2.setPos(50, 450);
                        point3.setPos(700,400);
                        points = 0;
                        break;                     
                    }


                    window.clear(Color::Red); // czyscimy ekran i ustawiamy tlo na czarno   

                     // napis ze przegrales
                    if (points == 0) {
                        window.draw(lost);
                    }else if(points==1){
                        window.draw(lost1);
                     }
                    else {
                        window.draw(lost2);
                    }

                    window.draw(again); // czy jeszcze raz? (napis)          
                    window.display(); // metoda wyœwietla obiekty, bez niej nic by sie wyswietlilo sie, biale tlo    
                    
                }
            }

            if (isIntersecting(reward, square))
            { // JESLI GRACZ WYGRA TO PRZEJDZ DO KOLEJNEJ PETLI GDZIE BEDZIE NAPIS ZE WYGRAL
                sound4.play();
                break;
            }

            window.display(); // metoda wyœwietla obiekty, bez niej nic by sie wyswietlilo sie, biale tlo    
        }

        while (true) // Petla z informacja ze wygrales
        {
            Event event; // Klasa do wy³apywania wszelkich zdarzeñ
            window.pollEvent(event); // wylapywanie zdarzen w obrêbie okna aplikacji, aby warunek ponizej dzialal (zamykanie na 'x)
            // metoda pollEvent zwraca prawde, jesli uda sie pobrac zdarzenia z kontenera, zmienna event dostaje informacje o odczytanym zdarzeniu,
            // w tym przypadku chodzi o zdarzenie "closed"



            if (event.type == Event::Closed) { // Jeœli klikamy 'X' w prawym gornym rogu to:

                window.close();
                break;
            }

            window.clear(Color::Green); // czyscimy ekran i ustawiamy tlo     

            // napis ze wygrales
            if (points == 0) {
                window.draw(win);
            }
            else if (points == 1) {
                window.draw(win2);
            }
            else if (points == 2) {
                window.draw(win3);
            }
            else {
                window.draw(win4);
            }
            window.draw(again);

            if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
                square.setPos();
                points = 0;
                point.setPos(50, 300);
                point2.setPos(50, 450);
                point3.setPos(700, 400);
                break;
            }


            window.display(); // metoda wyœwietla obiekty, bez niej nic by sie wyswietlilo sie, biale tlo    
        }

    }

    

}



