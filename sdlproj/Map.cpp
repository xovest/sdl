#include "Map.h"
#include "Game.h"
#include <fstream>
#include "ECS.h"
#include "Components.h"
extern Manager manager;

Map::Map(string texID, int ms, int ts) : textureID(texID), mapScale(ms), tileSize(ts) {
	scaledSize = ms * ts;
}

Map::~Map() {

}

void Map::LoadMap(string path, int sizeX, int sizeY) {
	char c;
	fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	for (int i = 0; i < sizeY; ++i)
		for (int j = 0; j < sizeX; ++j) {
			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;

			AddTile(srcX, srcY, j * scaledSize, i * scaledSize);
			mapFile.ignore();
		}

	mapFile.ignore();

	for (int i = 0; i < sizeY; ++i)
		for (int j = 0; j < sizeX; ++j) {
			mapFile.get(c);
			if (c == '1') {
				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("terrain", j * scaledSize, i * scaledSize, scaledSize);
				tcol.addGroup(Game::groupColliders);
			}
			mapFile.ignore();
		}

	mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xPos, int yPos) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xPos, yPos, tileSize, mapScale, textureID);
	tile.addGroup(Game::groupMap);
}