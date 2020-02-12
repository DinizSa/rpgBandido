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
	load("CharactersBits", "assets/tiles/CharactersBits.png");
	load("WildBits", "assets/tiles/MapsBits.png");
	load("Bandido", "assets/tiles/Bandido.png");
	load("Coelho", "assets/tiles/Coelho.png");
}
