#include "Obstacle.h"


Obstacle::Obstacle(float X, float Y, float Width, float Height) {
	shape.setPosition(X, Y);
	shape.setSize({ Width, Height });
	shape.setFillColor(Color::Blue);
	shape.setOrigin(Width / 2, Height / 2);
}

void Obstacle::draw(RenderTarget& target, RenderStates state) const
{//RenderTarget jest klas¹ bazow¹ aby tworzyc okno,tekstury itp 
	target.draw(shape, state); //rysowanie obiektu
}

float Obstacle::left() {
	return shape.getPosition().x - shape.getSize().x / 2; //wyznaczanie pozycji lewej krwêdzi, pobieranie skladowej x
}
float Obstacle::right() {
	return shape.getPosition().x + shape.getSize().x / 2;
}

float Obstacle::top() {
	return shape.getPosition().y - shape.getSize().y / 2;
}

float Obstacle::bottom() {
	return shape.getPosition().y + shape.getSize().y / 2;
}

Vector2f Obstacle::getPosition() {
	return shape.getPosition(); // zwraca aktualne polozenie shape
}





