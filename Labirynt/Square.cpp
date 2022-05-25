#include "Square.h"

Square::Square(float X, float Y)
{
	shape.setPosition(X, Y);  // ustalenie pocz¹tkowego po³o¿enia po odpaleniu gry
	shape.setSize(rectangleSize); // zmienna wektorowa rectangleSize ustawia rozmiar kwadratu
	shape.setFillColor(Color::Green); // ustawienie koloru
	shape.setOrigin(squareWidth / 2, squareHeight / 2); // punkt wzgledem ktorego dziej¹ siê przesuniêcia
}

void Square::draw(RenderTarget& target, RenderStates state) const
{ //RenderTarget jest klas¹ bazow¹ aby tworzyc okno,tekstury itp 
	target.draw(shape, state); //rysowanie obiektu, ogolnie metoda sprawia ze obiekt staje sie rysowalny/renderowalny
}

void Square::update()
{
	shape.move(velocity); // move to funkcja bezposrednio zwiazana z vectof2f, przekazujemy velocity jako wektor predkosci

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0) // jesli <- wcisniety i lewa krawedz kwadratu nie wychodzi poza zakres
	{
		velocity.x = -squareVelocity; // ustawiamy na ujemna, czyli w lewo
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < 800) // jezeli -> wcisniety i prawa krawedz kwadratu nie wychodzi poza zakres
	{
		velocity.x = squareVelocity; // ustawiamy na wartosc dodatnia, czyli w prawo
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && top() > 0) {
		velocity.y = -squareVelocity; // ustawiamy wartosc ujemna na y czyli w gore
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && bottom() < 600) {
		velocity.y = squareVelocity; // ustawiamy wartosc dodatnia na y czyli w dol
	}
	else {
		velocity.x = 0; // kwadrat nie bd sie ruszac jesli zaden przycisk nie bd wcisniety
		velocity.y = 0;
	}
}

float Square::left() {
	return shape.getPosition().x - shape.getSize().x / 2; //wyznaczanie pozycji lewej krwêdzi, pobieranie skladowej x
}
float Square::right() {
	return shape.getPosition().x + shape.getSize().x / 2;
}

float Square::top() {
	return shape.getPosition().y - shape.getSize().y / 2;
}

float Square::bottom() {
	return shape.getPosition().y + shape.getSize().y / 2;
}

void Square::setPos() {
	shape.setPosition(50, 100);
}

Vector2f Square::getPosition() { // zwraca pozycje kwadratu
	return shape.getPosition();
}