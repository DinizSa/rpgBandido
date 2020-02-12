#include <SFML/Graphics.hpp>
#include "assets.h"
#include "entity.h"
#include "maps.h"
#include "creature.h"
#include "inputHandler.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setFramerateLimit(60);
    Assets::get().LoadTextures();
    InputHandler inputHandler;
    Maps mapOne("map1.txt", "Wild", window.getSize().x, window.getSize().y);
    Creature player("Bandido", 100, 100, 0, 0, 34, 34, 1, 1, 1, 100, 3);
    Creature coelho("Coelho", 700, 500, 0, 0, 50, 50, 1, 1, 1, 50, 7);

    while (window.isOpen())
    {
        // Update
        player.move(mapOne, window.getSize().x, window.getSize().y);

        inputHandler.pollEvents(&window, &player);


        // display
        window.clear(sf::Color(0,0,0,255));

        mapOne.draw(&window);
        player.draw(&window);
        coelho.draw(&window);
        window.display();
    }

    return 0;
}