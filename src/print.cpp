
#include <SFML/Graphics.hpp>
#include<iostream>
#include<array>
#include"print.hpp"
using namespace std;
using namespace sf;

void print::print_board(array <array <char, 5>, 5> board, RenderWindow & window, RectangleShape Wall)
{
    Wall.setOutlineColor(Color::Black);
    Wall.setOutlineThickness(3);

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            switch (board[i][j])
            {
            case ' ':
                Wall.setFillColor(Color::Black);
                Wall.setPosition(Vector2f(j * 100.f, i * 100.f));
                map[i][j] = Wall;
                break;
            case 'x':
               
                Wall.setFillColor(Color::Red);
                Wall.setPosition(Vector2f(j * 100.f, i * 100.f));
                map[i][j] = Wall;
                break;
            case 'a':
                Wall.setFillColor(Color::White);
                Wall.setPosition(Vector2f(j * 100.f, i * 100.f));
                map[i][j] = Wall;
                break;
            case 'b':
                Wall.setFillColor(Color::Green);
                Wall.setPosition(Vector2f(j * 100.f, i * 100.f));
                map[i][j] = Wall;
                break;
            
            }
        }
        window.clear();

        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                window.draw(map[i][j]);
            }
        }
        window.display();
    }

}

void print::print_text(RenderWindow & window, string string_text)
{
    Font font;
    
    if (!font.loadFromFile("../Font/arial.ttf"))
    {
        // error...
    }

    // // window.draw(chess);
    Text text;

    // select the font
    text.setFont(font); // font is a Font

    // set the string to display
    text.setString(string_text);

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(Color::Red);

    // set the text style
    text.setStyle(Text::Bold);

    window.draw(text);
    window.display();
    sf::sleep(seconds(0.8));
    window.clear();
}

