#pragma once

#include "ECS.h"
#include "SDL.h"
#include <string>
#include "AssetManager.h"

class TileComponent : public Component {
public:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	~TileComponent() {
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY, int xPos, int yPos, int tSize, int tScale, string id) {
		texture = Game::assets->GetTexture(id);

		position.x = xPos;
		position.y = yPos;

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = tSize;

		destRect.x = xPos;
		destRect.y = yPos;
		destRect.w = destRect.h = tSize * tScale;
	}

	void update() override {
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};