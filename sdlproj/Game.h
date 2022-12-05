#pragma once
#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <iostream>
#include <vector>
using namespace std;

class ColliderComponent;
class AssetManager;

class Game {
	SDL_Window* window;
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int w, int h, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

	static bool isRunning;
	static SDL_Renderer* renderer;
	static SDL_Event e;
	static SDL_Rect camera;
	static AssetManager* assets;

	enum groupLabels : size_t {
		groupMap, groupPlayers, groupColliders, groupProjectiles
	};
};