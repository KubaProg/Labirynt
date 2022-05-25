#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

class Square:public Drawable // Drawable to klasa abstrakcyjna dla obiektow ktore bêd¹ rysowane
{
public:
	Square(float X, float Y); // Konstruktor
	Square() = default; // Konstruktor, default zeby nie trzeba bylo w .cpp implementowac
	~Square() = default; // Destruktor, -||-

	float right(); // krawedzie
	float left();
	float top();
	float bottom();
	void update(); // funkcja do aktualizacji stanu
	void setPos();

	Vector2f getPosition();


	void draw(RenderTarget& target, RenderStates state) const override;	//nadpisujemy funkcje draw z klasy renderwindow
																		// funcje wywo³ujemy jak chcemy coœ narysowaæ

	RectangleShape shape; // obiekt figury (w naszym przypadku kwadratu)

	const float squareWidth = 50;
	const float squareHeight = 50;
	const float squareVelocity = 3;

	Vector2f rectangleSize{ squareWidth, squareHeight }; // zmienna ktora ustawia w .cpp rozmiar
	Vector2f velocity{ squareVelocity, squareVelocity }; // wektor do poruszania sie w wszystkie strony (lewo/prawo, góra/dol)
														 // Takie fikuœne nawiasny, ¿eby nie musieæ definiowaæ tego w .cpp juz


};

