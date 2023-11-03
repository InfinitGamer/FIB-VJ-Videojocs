#ifndef _ENEMY_INCLUDE
#define _ENEMY_INCLUDE

#include "Sprite.h"
#include "TileMap.h"
#include <iostream>
#include "Score.h"
#include "SoundManager.h"

#define VX 1
#define SPAWN_DISTANCE 18 // 13 (tiles visibles) + 5 (tiles not visible)
#define FALL_STEP 4
#define JUMP_ANGLE_STEP 8
#define JUMP_HEIGHT_DYING 48

class Enemy {

public:
	Enemy();
	~Enemy();

	virtual void update(int deltaTime, float xmin, float xmax);
	void render();
	void setTileMap(TileMap *tileMap);
	void setPosition(const glm::vec2& pos);
	virtual int collision(const glm::vec2& pos, const glm::vec2& size);
	void setOriginalPosition(const glm::vec2& pos);
	virtual void restart();
	void changeDirection();
	virtual bool canKillEnemies() const;

	virtual void kill();

	void dyingAnimation();

	glm::ivec2 getPos() const;
	virtual glm::ivec2 getSize() const;

protected:
	SoundManager sound;
	Sprite* sprite;
	Texture spritesheet;
	glm::ivec2 tileMapDispl, posEnemy;
	glm::ivec2 originalPos;
	int dir;
	TileMap *map;
	bool bDelete, spawned;
	float currentTime;
	int startY, jumpAngle;

private:
	
};

#endif _ENEMY_INCLUDE