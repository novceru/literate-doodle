#include <SFML/Graphics.hpp>

int main()
{
    float shapeX = 0.0, shapeY = 0.0;
    float shapeXVel = 0.3, shapeYVel = 0.3;
    float shapeRadius = 30.f;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
    sf::CircleShape shape(shapeRadius);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(shapeX, shapeY));
    shape.setOutlineColor(sf::Color::Magenta);
    shape.setOutlineThickness(15);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shapeX += shapeXVel;
        shapeY += shapeYVel;
        if (shapeX >= 800 - shapeRadius || shapeX < 0) {
            shapeXVel *= -1;
        }
        if (shapeY >= 600 - shapeRadius || shapeY < 0) {
            shapeYVel *= -1;
        }
        shape.setPosition(sf::Vector2f(shapeX, shapeY));
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}