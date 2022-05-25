#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class Obstacle :public Drawable //publicznie dziedziczy po klasie Drawable
{
public:
	Obstacle(float X, float Y, float Width, float Height);
	~Obstacle() = default;

	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	//nadpisujemy funkcje draw z klasy renderwindow
	// funkcja sprawia ze obiekt jest rysowalny i mozliwy do renderowania na ekranie
	//  const override bo nadpisujemy z interfejsu f stala
	void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape shape;


};

