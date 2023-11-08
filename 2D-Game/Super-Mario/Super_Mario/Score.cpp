#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Score.h"

#define START_TIME 2
#define START_LIVES 1

void Score::init() {
	score = 0, lastScore = 0, coins = 0;
	world = make_pair(1, 1);
	time = START_TIME; lives = START_LIVES;
	bGameOver = false;

	if (!text.init("fonts/super-mario-bros-nes.ttf")) {
		cout << "Could not load font!!!" << endl;
	}
}

void Score::restart() {
	score = lastScore;
	time = START_TIME;
	coins = 0;
	bGameOver = false;
}

void Score::restartTime() {
	time = START_TIME;
}
void Score::restartLives() {
	lives = START_LIVES;
}

void Score::update(int deltaTime) {
	time -= (deltaTime/800.f);
	if (time < 0) bGameOver = true, time = 0;
}

void Score::render() {
	/* SCORE */
	text.render("SCORE", glm::vec2(32, 32), 20, glm::vec4(1, 1, 1, 1));
	text.render(to_string(score), glm::vec2(78, 56), 20, glm::vec4(1, 1, 1, 1));

	/* COINS */
	text.render("COINS", glm::vec2(208, 32), 20, glm::vec4(1, 1, 1, 1));
	text.render(to_string(coins), glm::vec2(256, 56), 22, glm::vec4(1, 1, 1, 1));

	/* WORLD */
	text.render("WORLD", glm::vec2(384, 32), 20, glm::vec4(1, 1, 1, 1));
	text.render(to_string(world.first) + "-" + to_string(world.second), glm::vec2(408, 56), 20, glm::vec4(1, 1, 1, 1));

	/* TIME */
	text.render("TIME", glm::vec2(560, 32), 20, glm::vec4(1, 1, 1, 1));
	if (lives > 0)
		text.render(to_string(int(time)), glm::vec2(572, 56), 20, glm::vec4(1, 1, 1, 1));

	/* LIVES */
	text.render("LIVES", glm::vec2(704, 32), 20, glm::vec4(1, 1, 1, 1));
	text.render(to_string(lives), glm::vec2(736, 56), 20, glm::vec4(1, 1, 1, 1));
}

void Score::increaseScore(int x) {
	score += x;
}

void Score::increaseCoins() {
	++coins;
}

void Score::updateWorld(int x, int y) {
	world = make_pair(x, y);
}

void Score::decreaseLive() {
	--lives;
	if (lives == 0) bGameOver = true;
}

double Score::getTime() {
	return time;
}

bool Score::gameOver() {
	return bGameOver;
}

void Score::timeToScore() {
	if (time == 0) return;
	--time;
	if (time < 0) time = 0;
	score += 50;
}