#include <SFML/Graphics.hpp>
#include <time.h>

class dog {
private:
	int x, y, size;
	bool ball = false;


public:
	dog(int xx, int yy) {
		x = xx;
		y = yy;
		size = 1;
	}

	int getx() {
		return x;
	}

	int gety() {
		return y;
	}

	void reset() {
		x = 30;
		y = 0;
	}

	void move(int m){
		if (m == 0 && x < 49) {
			x += size;
		}
		if (m == 1 && x > 0) {
			x -= size;
		}
		if (m == 2 && y < 49) {
			y += size;
		}
		if (m == 3 && y > 0) {
			y -= size;
		}
	}

	void setball(bool i){
		ball = i; 
	}
	bool hasball() {
		return ball;
	 }

};

class car {
private:
	int x, y, speed;
	int frame = 0;

public:
	car(int xx, int yy, int spd){
		x = xx;
		y = yy;
		speed = spd;
	}

	int getx() {
		return x;
	}

	int gety() {
		return y;
	}

	bool colid(int xx, int yy){
		if (x  == xx && y == yy) {
			return true;
		}
		return false;
	}


	void move() {
		if (frame > speed) {
			if (x > 50) {
				x = 0;
				speed = rand() % 40 + 20;
			}
			x += 1;
			frame = 0;
		}
		frame++;
	}
	
};

class ball {
private:
	int x, y;

public:
	ball(int xx, int yy) {
		x = xx;
		y = yy;
	}

	int getx() {
		return x;
	}

	int gety() {
		return y;
	}
	void setx(int xx) {
		x = xx;
	}

	void sety(int yy) {
		if (yy < 10) {
			y = yy + 10;
		}
		y = yy;
	}

};


int main()
{
	int hor = 50;
	int ver = 50;
	int pix = 16;
	int w = pix * ver;
	int h = pix * hor;
	bool keypress = false;
	int framerate = 100;


	srand(time(0));





	sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game");




	sf::Texture  ty, t0, t1, t2, t3, t4;
	ty.loadFromFile("image/yellow.png");

	t0.loadFromFile("image/grass1.png");

	t1.loadFromFile("image/grass.png");

	t2.loadFromFile("image/red.png");

	t3.loadFromFile("image/brown.png");

	t4.loadFromFile("image/ball.png");


	sf::Sprite spritey(ty);

	sf::Sprite sprite0(t0);

	sf::Sprite sprite1(t1);

	sf::Sprite sprite2(t2);

	sf::Sprite sprite3(t3);

	sf::Sprite sprite4(t4);


	ball ball(25, 25);
	dog dog(20, 20);
	car cars[6] = { {10, 10, 80}, {15,15, 90}, {20,20, 70}, {25,25, 71}, {30,30,85}, {35,35,100} };




	sf::Clock clock;

	float timer = 0.0f, delay = 0.1f;

	while (window.isOpen())

	{

		float time = clock.getElapsedTime().asSeconds();

		clock.restart();

		timer += time;

		sf::Event e;

		while (window.pollEvent(e))

		{

			if (e.type == sf::Event::Closed)
			{
				window.close();

			}

			if (sf::Event::KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dog.move(3);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dog.move(2);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dog.move(1);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dog.move(0);
			}

			break;
		}


		//if (framerate > 100) {
			for (int i = 0; i < 5; i++) {
				cars[i].move();
				//framerate = 0;
			}
		//}
		//framerate++;

		for (int i = 0; i < 5; i++) {
			if (cars[i].colid(dog.getx(), dog.gety())) {
				dog.reset();
				if (dog.hasball()) {
					ball.setx(rand() % hor);
					ball.sety(rand() % ver);
				}
			}
		}

		if (dog.getx() == ball.getx() && dog.gety() == ball.gety()) {
			ball.setx(60);
			ball.sety(60);
			dog.setball(true);
		}

		if (dog.gety() < 5 && dog.hasball()) {
			ball.setx(rand() % hor);
			ball.sety(rand() % ver);
			dog.setball(false);
		}


		if (timer > delay)

		{
			timer = 0;

		}


		window.clear();



		sprite1.setPosition(0, 0);
		window.draw(sprite1);

		sprite0.setPosition(0, 44 * 16);
		window.draw(sprite0);

		for (int i = 0; i < 5; i++) {

				sprite2.setPosition(cars[i].getx()*pix, cars[i].gety()*pix);

				window.draw(sprite2);

			}

			sprite3.setPosition(dog.getx()*pix, dog.gety()*pix);

			window.draw(sprite3);


			sprite4.setPosition(ball.getx()*pix, ball.gety()*pix);

			window.draw(sprite4);


			window.display();

		}

		return 0;
}