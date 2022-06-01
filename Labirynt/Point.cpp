#include "Point.h"

Point::Point(float X, float Y)
{
	circleShape.setPosition(X, Y); // ustalamy pozycje kulki
	circleShape.setRadius(pointRadius); // ustaw promien kó³ka na ballRadius z klasy Ball 
	circleShape.setFillColor(Color::Green); //ustawia kolor wypelnienia na bialy
	circleShape.setOrigin(pointRadius, pointRadius); // punkt wzgledem ktorego dzieja sie przesuniêcia
}

void Point::draw(RenderTarget& target, RenderStates state) const
{ //RenderTarget jest klas¹ bazow¹ aby tworzyc okno,tekstury itp 
	target.draw(circleShape, state); //rysowanie obiektu, ogolnie metoda sprawia ze obiekt staje sie rysowalny/renderowalny
}

void Point::getOut() {
	circleShape.setPosition(-100, -100);
}

void Point::setPos(int x, int y) {
	circleShape.setPosition(x, y);
}

float Point::left() {
	return circleShape.getPosition().x - circleShape.getRadius(); //wyznaczanie pozycji lewej krwêdzi, pobieranie skladowej x
}
float Point::right() {
	return circleShape.getPosition().x + circleShape.getRadius();
}

float Point::top() {
	return circleShape.getPosition().y - circleShape.getRadius();
}

float Point::bottom() {
	return circleShape.getPosition().y + circleShape.getRadius();
}

Vector2f Point::getPosition() { // zwraca pozycje kwadratu
	return circleShape.getPosition();
}
