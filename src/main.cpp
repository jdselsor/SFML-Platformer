#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <jsoncpp/json/json.h>

#include <iostream>
#include <fstream>

void pollInput ();

int main()
{
    std::ifstream ifs("./assets/config.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);

    std::cout << "Fullscreen: " << obj["fullscreen"].asString() << std::endl;
    std::cout << "Width: " << obj["width"].asUInt() << ", height: " << obj["height"].asUInt() << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
