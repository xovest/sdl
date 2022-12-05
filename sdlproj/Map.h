#pragma once
#include <string>
using namespace std;

class Map {
	string textureID;
	int mapScale, tileSize;
	int scaledSize;
public:
	Map(string texID, int ms, int ts);
	~Map();

	void LoadMap(string path, int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int xPos, int yPos);
};