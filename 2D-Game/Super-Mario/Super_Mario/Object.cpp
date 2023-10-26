#include "Object.h"
Object::Object(const glm::vec2& pos, const glm::vec2& size, const glm::vec2& tileMapDisplay, TileMap* m) {
	this->pos = pos;
	this->size = size;
	this->tileMapDisplay = tileMapDisplay;
	map = m;
	isUsed = false;
}

bool Object::collide(const glm::vec2& plyPos, const glm::vec2& plySize) {
	float minx1 = pos.x;
	float miny1 = pos.y;
	float maxx1 = pos.x + size.x;
	float maxy1 = pos.y + size.y;

	float minx2 = plyPos.x;
	float miny2 = plyPos.y;
	float maxx2 = plyPos.x + plySize.x;
	float maxy2 = plyPos.y + plySize.y;

	bool a = (minx1 < maxx2) && (minx2 < maxx1);
	bool b = (miny1 < maxy2) && (miny2 < maxy1);

	return a && b;
}