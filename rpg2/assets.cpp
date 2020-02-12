#include "assets.h"

Assets::Assets() {

}

Assets::~Assets() {

}

void Assets::LoadTextures() {
	auto load = [&](string sName, string sFileName) {
		sf::Texture texture;
		texture.loadFromFile(sFileName);
		m_mapsTextures[sName] = texture;
	};

	// Load assets
	load("Town1", "assets/tiles/tile.png");
	load("BG", "assets/BG.png");
	load("DinoStand1", "assets/dino/Idle (1).png");
	load("characterBits", "assets/tiles/SpritesBits.png");
	load("WildBits", "assets/tiles/MapsBits.png");
	load("Bandido", "assets/tiles/Bandido.png");
}
