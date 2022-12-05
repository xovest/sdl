#pragma once
#include "Game.h"

class GameObject {
	int xPos, yPos;
	SDL_Texture* objectTexture;
	SDL_Rect sourceRectangle, destinationRectangle;
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();
	void update();
	void render();
};