#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "Projection.h"
#include "Score.h"
#include "StartMenu.h"

// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene {

public:
	Scene();
	~Scene();

	void init();
	void change();
	void update(int deltaTime, bool inMenu);
	void render();

	glm::ivec2 getTilePos();

private:
	void initShaders();

private:
	TileMap *map;
	Player *player;
	ShaderProgram texProgram;
	float currentTime;

	Projection camera;
	glm::mat4 projection;
	Score *score;
};


#endif // _SCENE_INCLUDE

