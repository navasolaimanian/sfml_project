#ifndef PRINT_H
#define PRINT_H
#include<iostream>
#include<array>
class print
{
private:
    std::array<std::array<sf::RectangleShape, 5>, 5> map;

public:
    void print_board(std::array <std::array <char, 5>, 5>, sf::RenderWindow &, sf::RectangleShape);
    void print_text(sf::RenderWindow &, std::string);
};
#endif 

