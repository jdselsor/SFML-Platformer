#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
float x = 0.0f;

void pollInput ();

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
    sf::RectangleShape shape(sf::Vector2f(120.f, 50.f));
    shape.setPosition (400.0f - 60.0f, 300.0f - 25.0f);

    sf::View view2(sf::FloatRect(0.f, 0.f, (float) WINDOW_WIDTH, (float) WINDOW_HEIGHT));

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

        pollInput();

        view2.setRotation(x);

        window.clear();

        window.setView (view2); // This updates the view.
        window.draw(shape);

        window.display();
    }

    return 0;
}

void pollInput ()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        //std::cout << "Left Key Pressed" << std::endl;
        x -= 0.05f;
        std::cout << "X: " << x << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        //std::cout << "Left Key Pressed" << std::endl;
        x += 0.05f;
        std::cout << "X: " << x << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        // left key is pressed: move our character
        //std::cout << "Left Key Pressed" << std::endl;
        x = 0.0f;
    }
}
