#pragma once
#include "Components.h"
#include "SDL.h"
#include <cstring>
#include "TextureManager.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	TransformComponent* transform;

	ColliderComponent(string t) {
		tag = t;
	}

	ColliderComponent(string t, int xPos, int yPos, int size) {
		tag = t;
		collider.x = xPos;
		collider.y = yPos;
		collider.h = collider.w = size;
	}

	void init() override {
		if (!entity->hasComponent<TransformComponent>())
			entity->addComponent<TransformComponent>();

		transform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("assets/ColTex.png");
		srcR = { 0, 0, 32, 32 };
		destR = { collider.x, collider.y, collider.w, collider.h };


	}

	void update() override {
		if (tag != "terrain") {
			collider.x = static_cast<int>(transform->position.x);
			collider.y = static_cast<int>(transform->position.y);
			collider.w = transform->width * transform->scale;
			collider.h = transform->height * transform->scale;
		}

		destR.x = collider.x - Game::camera.x;
		destR.y = collider.y - Game::camera.y;
	}

	void draw() override {
		TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);
	}
};