#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
	objectTexture = TextureManager::LoadTexture(textureSheet);
	xPos = x;
	yPos = y;
}

void GameObject::update() {
	++xPos;
	++yPos;

	sourceRectangle.h = 32;
	sourceRectangle.w = 32;
	sourceRectangle.x = 0;
	sourceRectangle.y = 0;

	destinationRectangle.w = sourceRectangle.w * 2;
	destinationRectangle.h = sourceRectangle.h * 2;
	destinationRectangle.x = xPos;
	destinationRectangle.y = yPos;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &sourceRectangle, &destinationRectangle);
}