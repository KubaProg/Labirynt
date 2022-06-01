#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

class Point :public Drawable
{
public:
	Point(float X, float Y); // Konstruktor
	Point() = default; // Konstruktor, default zeby nie trzeba bylo w .cpp implementowac
	~Point() = default; // Destruktor, -||-

	float right(); // krawedzie
	float left();
	float top();
	float bottom();
	void getOut();
	void setPos(int x, int y);

	Vector2f getPosition();

	void draw(RenderTarget& target, RenderStates state) const override;	//nadpisujemy funkcje draw z klasy renderwindow																// funcje wywo³ujemy jak chcemy coœ narysowaæ

	CircleShape circleShape; // obiekt figury (w naszym przypadku kola)

	const float pointRadius = 10;

};

