#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

class Reward:public Drawable
{
public:
	Reward(float X, float Y); // Konstruktor
	Reward(float X, float Y, Color color);
	Reward() = default; // Konstruktor, default zeby nie trzeba bylo w .cpp implementowac
	~Reward() = default; // Destruktor, -||-

	float right(); // krawedzie
	float left();
	float top();
	float bottom();
	void update(); // funkcja do aktualizacji stanu nagrody
	void updateMonster(); // funkcja do aktualizacji stanu potwora

	Vector2f getPosition();


	void draw(RenderTarget & target, RenderStates state) const override;	//nadpisujemy funkcje draw z klasy renderwindow
																		// funcje wywo³ujemy jak chcemy coœ narysowaæ

	CircleShape circleShape; // obiekt figury (w naszym przypadku kola)

	const float rewardRadius = 10;
	const float rewardSpeed =  1.5;

	Vector2f velocity{0,rewardSpeed}; // wektor do poruszania sie w wszystkie strony (lewo/prawo, góra/dol)

};

