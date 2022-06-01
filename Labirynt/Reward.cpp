#include "Reward.h"

Reward::Reward(float X, float Y)
{
	circleShape.setPosition(X, Y); // ustalamy pozycje kulki
	circleShape.setRadius(rewardRadius); // ustaw promien kó³ka na ballRadius z klasy Ball 
	circleShape.setFillColor(Color::White); //ustawia kolor wypelnienia na bialy
	circleShape.setOrigin(rewardRadius,rewardRadius); // punkt wzgledem ktorego dzieja sie przesuniêcia
}

Reward::Reward(float X, float Y, Color color)
{
	circleShape.setPosition(X, Y); // ustalamy pozycje kulki
	circleShape.setRadius(rewardRadius); // ustaw promien kó³ka na ballRadius z klasy Ball 
	circleShape.setFillColor(color); //ustawia kolor wypelnienia na bialy
	circleShape.setOrigin(rewardRadius, rewardRadius); // punkt wzgledem ktorego dzieja sie przesuniêcia
}

void Reward::draw(RenderTarget& target, RenderStates state) const
{ //RenderTarget jest klas¹ bazow¹ aby tworzyc okno,tekstury itp 
	target.draw(circleShape, state); //rysowanie obiektu, ogolnie metoda sprawia ze obiekt staje sie rysowalny/renderowalny
}

void Reward::update()
{
	circleShape.move(velocity); // move to funkcja bezposrednio zwiazana z vectof2f, przekazujemy velocity jako wektor predkosci

	if (bottom() > 400) {
		velocity = -velocity;
	}

	if (top() < 200) {
		velocity.y = rewardSpeed;
	}
}

void Reward::updateMonster()
{
	circleShape.move(velocity);

	if (bottom() > 650) {
		velocity = -velocity;
	}

	if (top() < 300) {
		velocity.y = rewardSpeed;
	}

}

float Reward::left() {
	return circleShape.getPosition().x - circleShape.getRadius(); //wyznaczanie pozycji lewej krwêdzi, pobieranie skladowej x
}
float Reward::right() {
	return circleShape.getPosition().x + circleShape.getRadius();
}

float Reward::top() {
	return circleShape.getPosition().y - circleShape.getRadius();
}

float Reward::bottom() {
	return circleShape.getPosition().y + circleShape.getRadius();
}

Vector2f Reward::getPosition() { // zwraca pozycje kwadratu
	return circleShape.getPosition();
}
