#pragma once

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"

class ProjectileComponent : public Component {
	TransformComponent* transform;
	int range = 0, speed = 0, distance = 0;
	Vector2D velocity;
public:
	ProjectileComponent(int rng, int spd, Vector2D vel) : range(rng), speed(spd), velocity(vel) {}

	~ProjectileComponent() {}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		transform->velocity = velocity;
		std::cout << transform->position << std::endl;
	}

	void update() override {
		distance += speed;

		if (distance > range) {
			std::cout << "Out of Range\n";
			entity->destroy();
		}
		else if (transform->position.x > Game::camera.x + Game::camera.w ||
			transform->position.x < Game::camera.x ||
			transform->position.y > Game::camera.y + Game::camera.h ||
			transform->position.y < Game::camera.y
			) {
			std::cout << "Out of Bounds\n";
			entity->destroy();
		}
	}
};